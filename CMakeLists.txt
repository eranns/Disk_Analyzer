cmake_minimum_required(VERSION 3.17)
project(Disk_Analyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Disk_Analyzer main.cpp src/FSFile.cpp src/FSFile.h src/FSthreadpool.cpp src/FSthreadpool.h src/FSTask.h)
find_package(Boost COMPONENTS system filesystem REQUIRED)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(Disk_Analyzer
            ${Boost_FILESYSTEM_LIBRARY}
            ${Boost_SYSTEM_LIBRARY}
            )
endif()

