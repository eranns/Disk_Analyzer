#ifndef DISK_ANALYZER_FSTHREADPOOL_H
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <queue>
#include <unordered_map>
#include <boost/filesystem.hpp>
#include <boost/container_hash/hash.hpp>
#include "FSTask.h"
#include "FSFile.h"
#include <set>


namespace fs=boost::filesystem;

struct hash_struct
{
    size_t operator()(const fs::path& path) const
    {
        return fs::hash_value(path);
    }
};

#define DISK_ANALYZER_FSTHREADPOOL_H
#endif //DISK_ANALYZER_FSTHREADPOOL_H
typedef FSTask<fs::path> pathTask;
class FSthreadpool{
private:
    std::atomic_bool _fin=false; // state of thread pool (finished or not)
    std::mutex _tasks_m; // mutex for tasks queue
    std::mutex _directories_m; // mutex for directories map
    std::condition_variable _tasks_cond; // condition variable for tasks queue
    std::unordered_map<fs::path,FSFile*,hash_struct> _directories; // map lookup for directories
    std::queue<pathTask> _tasks; // tasks queue
    std::set<fs::path> _ignore_paths; //paths to ignore while scanning
    fs::path _startPath; // start path of the scanner
    FSFile* _startFile; // the root of the tree in the end of the run
    int _size=std::thread::hardware_concurrency(); // number of consumers
    std::vector<std::thread> _pool; // pool of vectors
    void shutdown(); // shutdown pool
    void consumer(); // consumer task
    void consumerTask();
    void producer(); // producer task
    void producer_helper(const fs::path&);
    void init_ignorePaths();

    //queue
    void q_push(pathTask);
    bool q_pop(pathTask&);
    bool q_empty_no_lock();

    //map
    void m_insert(fs::path,FSFile*);
    FSFile* m_find(fs::path);



public:
    FSthreadpool(std::string path);
    ~FSthreadpool();
    void start();
    FSFile* getrootFile();

    void sortFileTree(FSFile *rootPath);
};