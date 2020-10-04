#include <iostream>
#include "src/FSthreadpool.h"
#include <map>
#include <chrono>


void Clear();

void print_intro(std::chrono::seconds);

enum class input_options
{
    back,
    clear,
    print,
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
                    {"default",input_options::def}
            };
    bool quit_program=false;
    FSthreadpool t("/Users/erans/Downloads");
    auto start = std::chrono::high_resolution_clock::now();
    t.start();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    FSFile* current =t.startFile();
    Clear();
    print_intro(duration);
    while(!quit_program){

        std::cout<<"current directory :"<<current->getName()<<std::endl;
        std::cout<<"use "<<std::endl
        <<"\t :p to print directory "<<std::endl
        <<"\t :b to go to the previous directory"<<std::endl
        <<"\t :c to clear command line window"<<std::endl
        <<"\t :q to quit"<<std::endl
        <<"\t name of folder to go into it"<<std::endl;
        std::string chosed_dir;

        if(std::cin >> chosed_dir){
            input_options input = get_option(string_to_input_options,chosed_dir,input_options::def);
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
                    Clear();
                    break;
                }
                case input_options::print : {
                    std::cout<<*current<<std::endl;
                    break;
                }
                case input_options::def : {
                    bool found_directory = false;
                    for (FSFile *f:current->getChildren()) {
                        if (chosed_dir.compare(f->getName())==0) {
                            std::cout<<f->getName()<<std::endl;
                            current = f; //new current
                            found_directory = true;
                            break;
                        }
                    }
                    if (!found_directory) {
                        std::cout << "You have chosen invalid directory";
                    }
                    break;
                }

            }
        }
    }

    return 0;
}

void print_intro(std::chrono::seconds dur) {
    std::cout<<"########## Disk Analyzer ###############"<<std::endl;
    std::cout<<"Scan took "<< dur.count()/60<< " minutes" << std::endl<<std::endl<<std::endl;
}

void Clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
