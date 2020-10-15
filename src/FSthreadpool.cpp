#include "FSthreadpool.h"



FSthreadpool::FSthreadpool(std::string path) {
    _pool.reserve(_size);
    _startPath=fs::path(path);
    init_ignorePaths();
    _startFile = new FSFile(_startPath.filename().string(),0,nullptr,'d');
}
FSthreadpool::~FSthreadpool() {
    delete(_startFile);
}

//pool related functions
void FSthreadpool::start() {
        std::thread t1([&]{
            producer();
            _fin=true;
            std::this_thread::sleep_for(std::chrono::seconds(10));
            shutdown();
        });
        std::thread t2([&]{
            consumer();
        });
        t1.join();
        t2.join();

    };
void FSthreadpool::shutdown(){
    _tasks_cond.notify_all();
    _startFile->sort_children();
    _directories.erase(_directories.begin(),_directories.end());
}

/*
 * some paths are excluded from signing as they require SIP to be disabled on OSX
 * see https://support.apple.com/en-us/HT204899
 */
void FSthreadpool::init_ignorePaths(){
    _ignore_paths.insert(fs::path("/private/var"));
    _ignore_paths.insert(fs::path("/System/Volumes"));
    _ignore_paths.insert(fs::path("/System/Library"));
    _ignore_paths.insert(fs::path("/Library/Application Support"));
    _ignore_paths.insert(fs::path("/var/db"));
    _ignore_paths.insert(fs::path("/var/folders"));
    _ignore_paths.insert(fs::path("/dev/fd"));
}
//producer functions
/*
 * Iterating over folders and files in a recursive way with producer_helper.
 * Populating tasks of files and directories into a map
 */
void FSthreadpool::producer() {
    if (fs::exists(_startPath)) {
        if (fs::is_directory(_startPath)) { //validating input
            std::string name = _startPath.filename().string();
            FSFile *rootpath = _startFile;
            m_insert(_startPath, rootpath); //inserting to directories map
            fs::directory_options opt = fs::directory_options::pop_on_error;
            boost::system::error_code ec;

            try{
                for(auto& entry :fs::directory_iterator(_startPath,opt,ec)){
                    if(fs::is_regular_file(entry.path()) && !fs::is_symlink(entry.path())) {
                        pathTask task (entry.path());
                        q_push(task);
                    }
                    else if(fs::is_directory(entry.path())){
                        FSFile *f = new FSFile(entry.path().filename().string(),0,rootpath,'d');
                        rootpath->add_children(f);
                        m_insert(entry.path(),f);
                        std::cout<<"Scanning "<<entry.path()<<std::endl;
                        producer_helper(entry.path());
                    }

                }
            }
            catch(boost::filesystem::filesystem_error e){
                std::cout<<e.what()<<std::endl;
            }


        } else {
            //TODO : throw relevant error . path does is not exists or not a directory
        }
    }
}

void FSthreadpool::producer_helper(const fs::path &path) {
for(auto& entry: fs::directory_iterator(path,fs::directory_options::pop_on_error)){

    if(fs::is_regular_file(entry.path() ) && !fs::is_symlink(entry.path()) && entry.path().filename().string().at(0)!='.') {
        pathTask task (entry.path());
        q_push(task);

    }
    else if(is_directory(entry.path())  && !fs::is_symlink(entry.path())){
        if(_ignore_paths.find(entry.path()) != _ignore_paths.end()){
            continue;
        }
        FSFile *parent = m_find(entry.path().parent_path());
        FSFile *f = new FSFile(entry.path().filename().string(),0,parent,'d');
        m_insert(entry.path(),f);
        if(parent!=nullptr && parent->getName().at(0)!='.'){
            parent->add_children(f);
            producer_helper(entry.path());
        }
    }

}


}


//consumer function

/*
 * Handling tasks of files
 * 1.Popping files out of the task queue until its empty
 * 2.calculating file size and update parents recursively
 */
void FSthreadpool::consumer() {
        for(int ii = 0; ii < _size; ii++)
        {
            _pool.push_back(std::thread([&]{
                consumerTask();

            }));
            _pool.back().join();
            if(_fin){
                break;
            }
        }
    }

/*
 * Handling tasks of files
 * 1.Popping files out of the task queue until its empty
 * 2.calculating file size and update parents recursively
 */
void::FSthreadpool::consumerTask(){
    while(!_tasks.empty() || !_fin) {
        pathTask task;
        q_pop(task);
        if (task.getTask() != "") {
            FSFile *parent = m_find(task.getTask().parent_path());
            if (parent != nullptr) {
                parent->add_children(
                        new FSFile(task.getTask().filename().string(), fs::file_size(task.getTask()), parent, 'f'));
                parent->update_size(fs::file_size(task.getTask()));
            }
        }
    }
}

/////// queue functions
void FSthreadpool::q_push(pathTask task) {
    std::lock_guard<std::mutex> lock(_tasks_m);
    _tasks.push(task);
    _tasks_cond.notify_one();
}
bool FSthreadpool::q_pop(pathTask & task) {
    std::unique_lock<std::mutex> lock (_tasks_m);
    _tasks_cond.wait(lock,[this]{return !q_empty_no_lock() || _fin;});
    if(!q_empty_no_lock()){
        task = _tasks.front();
        _tasks.pop();
    }


}

bool FSthreadpool::q_empty_no_lock() {
    return _tasks.empty();
}






/////// map functions

FSFile* FSthreadpool::m_find(fs::path key) {
    std::lock_guard lck(_directories_m);
    auto pos = _directories.find(key);
    if (pos == _directories.end()) {
        return nullptr;
    } else {
        FSFile* res = pos->second;
        return res;
    }
}
void FSthreadpool::m_insert(fs::path key,FSFile* val) {
    std::lock_guard lock(_directories_m);
    _directories[key]=val;


}


 FSFile *FSthreadpool::getrootFile() {
    return _startFile;
}

void FSthreadpool::sortFileTree(FSFile* path){
    for(FSFile* f:_startFile->getChildren()){
        if(f->getType()=='d'){
            sortFileTree(f);
        }
    }
    path->sort_children();
}

