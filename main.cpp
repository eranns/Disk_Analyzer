#include <iostream>
#include "src/FSthreadpool.h"
#include <map>
#include <chrono>


void Clear();

void print_intro(std::chrono::duration<long long int, std::ratio<1, 1>> duration);

enum class input_options
{
    back,
    clear,
    quit
};


int main() {
    std::map<std::string, input_options> string_to_input_options =
            {
                    { ":b", input_options::back },
                    { ":c", input_options::clear},
                    {":q",input_options::quit}
            };
    bool quit_program=false;
    FSthreadpool t("/");
    auto start = std::chrono::high_resolution_clock::now();
    t.start();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    FSFile* current =t.startFile();
    Clear();
    print_intro(duration);
    while(!quit_program){

        std::cout<<*current<<std::endl;
        std::string chosed_dir;

        if(std::cin >> chosed_dir){
            input_options input = string_to_input_options[chosed_dir];
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
                default: {
                    bool found_directory = false;
                    for (FSFile *f:current->getChildren()) {
                        if (chosed_dir.compare(f->getName())) {
                            current = f; //new current
                            found_directory = true;
                        }
                    }
                    if (!found_directory) {
                        std::cout << "You have chosen invalid directory";
                    }
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
