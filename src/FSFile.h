#ifndef DISK_ANALYZER_FSFILE_H
#include <string>
#include <vector>
#include <mutex>
#include <iostream>
#include <sstream>
#define DISK_ANALYZER_FSFILE_H

#endif //DISK_ANALYZER_FSFILE_H
/**
 * File representation
 * name - name of the file
 * _size - size of the file
 * _parent - pointer to file parent
 * _children vector of pointers of children under this path (applies to directories)
 * _type - directory or file (d or f)
 * _mutex - prevent thread race while updating size or children
 */
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
    FSFile(std::string name, uintmax_t size, FSFile* parent,char type);
    ~FSFile();
    void add_children(FSFile*); // adding children to a file
    void update_size(uintmax_t); // updating size of a file
    std::string getName() const;
    uintmax_t getSize() const;
    char getType();
    FSFile *getParent();
    char getType() const;
    std::vector<FSFile*> getChildren() const;
    friend std::ostream& operator<<(std::ostream& os,const FSFile&);
    bool operator > (const FSFile& f) const;
    double size_conversion(std::string&) const;
    void sort_children();

    std::vector<std::string> getChildrenAsString() const;
};