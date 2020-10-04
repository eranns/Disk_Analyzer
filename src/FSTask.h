#ifndef DISK_ANALYZER_FSTASK_H
#define DISK_ANALYZER_FSTASK_H

template<class T>
class FSTask {
private:
    T _task;

public:
    FSTask(){};
    FSTask(T task) :_task(task){};
    T& getTask(){
        return _task;
    }

};


#endif //DISK_ANALYZER_FSTASK_H
