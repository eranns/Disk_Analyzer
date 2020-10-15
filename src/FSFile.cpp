#include "FSFile.h"


FSFile::FSFile(std::string name, uintmax_t size, FSFile *parent, char type) : _name(name) , _size(size) , _parent(parent),_type(type){};


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

std::string FSFile::getName() const{
    return _name;
}
uintmax_t FSFile::getSize()const {
    return _size;
}

char FSFile::getType() const {
    return _type;
}
std::vector<FSFile*> FSFile::getChildren() const {
    return _children;
}
std::vector<std::string> FSFile::getChildrenAsString() const{
    std::vector<std::string> res;
    for(int i=0;i<_children.size();i++){
        res.push_back(_children[i]->getName());
    }
    return res;
}
double FSFile::size_conversion(std::string& measure)const{
    double size;
    if(_size>1000000000){
        measure="GiB";
        size=static_cast<double>(_size)/(1024*1024*1024);
    }
    else if(_size>1000000){
        measure="MiB";
        size=static_cast<double>(_size)/(1024*1024);
    }
    else{
        measure="B";
        size=_size;
    }
    return size;

}
std::ostream& operator<<(std::ostream& os, const FSFile& file ){
    std::stringstream sstr;
    std::string measure="B";

    sstr << file.getName()<<'\t'<<file.size_conversion(measure)<<" "<<measure<<std::endl;


    for(FSFile *f:file.getChildren()){

        sstr<<f->getType()<<'\t'<<f->getName()<<'\t'<<f->size_conversion(measure)<<" "<<measure<<std::endl;
    }
    std::string out=sstr.str();
    return os << out <<"\t"<<std::endl;

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
char FSFile::getType() {
    return _type;
}


FSFile::~FSFile(){
    for(FSFile* f: _children){
        delete(f);
    }
}

