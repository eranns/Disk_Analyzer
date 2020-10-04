#ifndef DISK_ANALYZER_FSTHREADPOOL_H
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <queue>
#include <map>
#include <boost/filesystem.hpp>
#include "FSTask.h"
#include "FSFile.h"
#include <set>


namespace fs=boost::filesystem;
#define DISK_ANALYZER_FSTHREADPOOL_H
#endif //DISK_ANALYZER_FSTHREADPOOL_H
typedef FSTask<fs::path> pathTask;
class FSthreadpool{
private:
    std::atomic_bool _fin=false; // state of thread pool (finished or not)
    std::mutex _tasks_m; // mutex for tasks queue
    std::mutex _directories_m; // mutex for directories map
    std::condition_variable _tasks_cond; // condition variable for tasks queue
    std::map<std::string,FSFile*> _directories; // map lookup for directories
    std::queue<pathTask> _tasks; // tasks queue
    std::set<fs::path> _ignore_paths;
    fs::path _startPath;
    FSFile* _startFile;
    int _size=std::thread::hardware_concurrency();
    std::vector<std::thread> _pool;
    void shutdown();
    void consumer();
    void producer();
    void producer_helper(const fs::path&);
    void consumerTask();

    //queue
    void q_push(pathTask);
    bool q_pop(pathTask&);
    bool q_empty_no_lock();

    //map
    void m_insert(std::string,FSFile*);
    FSFile* m_find(std::string);

public:
    FSthreadpool(std::string path){
        _pool.reserve(_size);
        _startPath=fs::path(path);
        init_ignorePaths();
    _startFile = new FSFile(_startPath.filename().string(),0,nullptr,'d');
}
    ~FSthreadpool(){};
    void start();
    void init_ignorePaths();
    FSFile *startFile();
};