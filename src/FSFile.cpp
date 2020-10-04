#include "FSFile.h"

void FSFile::add_children(FSFile *f) {
    std::lock_guard lock(_mutex);
    if(f!=nullptr){
        _children.push_back(f);
    }
}
void FSFile::update_size(uintmax_t size){
    std::lock_guard lock(_mutex);
    _size+=size;
    if(_parent!=nullptr) //updating parent for each time we update this folder. avoiding error on startPath
        _parent->update_size(size);
}

std::string FSFile::getName() {
    return _name;
}
uintmax_t FSFile::getSize() {
    return _size;
}
std::vector<FSFile*> FSFile::getChildren() {
    return _children;
}
std::ostream& operator<<(std::ostream& os,const FSFile& file){
    std::stringstream sstr;
    sstr << file._name<<'\t'<<file._size<<std::endl;
    for(FSFile *f:file._children){
        sstr<<'\t'<<f->getName()<<'\t'<<f->getSize()<<std::endl;
    }
    std::string out=sstr.str();
    return os << out <<"\t"<<file._size;

}
bool FSFile::comparePtrToFile(FSFile *a, FSFile *b) {
    return (*a> *b);
}
bool FSFile::operator>(const FSFile &f) const {
    return (_size > f._size);

}void FSFile::sort_children() {
    std::sort(_children.begin(),_children.end(),&FSFile::comparePtrToFile );
}

FSFile * FSFile::getParent() {
    return _parent;
}

