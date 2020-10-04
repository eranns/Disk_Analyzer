#ifndef DISK_ANALYZER_FSFILE_H
#include <string>
#include <vector>
#include <mutex>
#include <iostream>
#include <sstream>
#define DISK_ANALYZER_FSFILE_H

#endif //DISK_ANALYZER_FSFILE_H
class FSFile{
private:
    std::string _name;
    uintmax_t _size;
    FSFile* _parent;
    std::vector<FSFile*> _children;
    char _type;
    std::mutex _mutex;
    static bool comparePtrToFile(FSFile *a, FSFile *b);

public:
    FSFile(std::string name, uintmax_t size, FSFile* parent,char type) : _name(name) , _size(size) , _parent(parent),_type(type){};
    ~FSFile(){
        for(FSFile* f: _children){
            delete(f);
        }
    }
    void add_children(FSFile*);
    void update_size(uintmax_t);
    std::string getName() const;
    uintmax_t getSize() const;
    FSFile *getParent();
    char getType() const;
    std::vector<FSFile*> getChildren() const;
    friend std::ostream& operator<<(std::ostream& os,const FSFile&);
    bool operator > (const FSFile& f) const;
    double size_conversion(std::string&) const;


    void sort_children();

};