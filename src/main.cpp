#include <iostream>
#include "FSthreadpool.h"
#include <map>
#include <chrono>


void print_help();
void print_intro(std::chrono::seconds);
void ClearScreen();

enum class input_options
{
    back,
    clear,
    print,
    help,
    def,
    quit
};

template<typename MAP>
const typename MAP::mapped_type& get_option(const MAP& m,
                                                  const typename MAP::key_type& key,
                                                  const typename MAP::mapped_type& defval)
{
    typename MAP::const_iterator it = m.find(key);
    if (it == m.end())
        return defval;

    return it->second;
}


int main() {
    std::map<std::string, input_options> string_to_input_options =
            {
                    { ":b", input_options::back },
                    { ":c", input_options::clear},
                    {":p",input_options::print},
                    {":q",input_options::quit},
                    {":h",input_options::help},
                    {"default",input_options::def}
            };
    bool quit_program=false;
    FSthreadpool* t=new FSthreadpool("/");
    auto start = std::chrono::high_resolution_clock::now();
    t->start();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    FSFile* current =t->getrootFile();
    ClearScreen();
    print_intro(duration);
    while(!quit_program){

        std::cout<<"current directory : "<<current->getName()<<std::endl;

        std::string option;

        if(std::getline(std::cin, option)){
            input_options input = get_option(string_to_input_options, option, input_options::def);
            switch(input) {
                case input_options::back : {
                    if (current->getParent() != nullptr) {
                        current = current->getParent();
                    }
                    break;
                }
                case input_options::quit : {
                    quit_program = true;
                    break;
                }
                case input_options::clear : {
                    ClearScreen();
                    break;
                }
                case input_options::print : {
                    std::cout<<*current<<std::endl;
                    break;
                }
                case input_options::help : {
                    print_help();
                    break;
                }
                case input_options::def : {
                    bool found_directory = false;
                    for (FSFile *f:current->getChildren()) {
                        if (option.compare(f->getName()) == 0) {
                            if(f->getType()=='d'){
                                current = f; //new current
                                if(!std::is_sorted(f->getChildren().begin(),f->getChildren().end())){
                                    f->sort_children();
                                }
                                found_directory = true;
                            }
                            else{
                                std::cout<<"Please choose a directory and not a file"<<std::endl;
                            }

                        }

                    }

                    if (!found_directory) {
                        std::cout << "invalid directory name"<<std::endl;
                    }
                    break;
                }

            }
        }
    }
    current=t->getrootFile();free(t);delete(current);return 0;
}

void ClearScreen() {
    std::cout << "\033[2J" << std::flush;
}

void print_intro(std::chrono::seconds dur) {
    std::cout<<"########## Welcome to Disk Analyzer ###############"<<std::endl;
    std::cout<<"Scan took "<< dur.count()/60<< " minutes" << std::endl<<std::endl<<std::endl;
}
void print_help(){
    std::cout<<"____ help ______ "<<std::endl
             <<"\t :p to print directory "<<std::endl
             <<"\t :b to go to the previous directory"<<std::endl
             <<"\t :c to clear command line window"<<std::endl
             <<"\t :q to quit"<<std::endl
             <<"\t name of folder to go into it"<<std::endl<<std::endl;
}



