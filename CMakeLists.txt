cmake_minimum_required(VERSION 3.17)
project(Disk_Analyzer)

set(CMAKE_CXX_STANDARD 17)
include_directories(/usr/local/opt/ncurses/include)

link_directories(/usr/local/opt/ncurses/lib)

add_executable(Disk_Analyzer src/main.cpp src/FSFile.cpp src/FSFile.h src/FSthreadpool.cpp src/FSthreadpool.h src/FSTask.h)
target_link_libraries(Disk_Analyzer menu ncurses)
find_package(Boost COMPONENTS system filesystem REQUIRED)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(Disk_Analyzer
            ${Boost_FILESYSTEM_LIBRARY}
            ${Boost_SYSTEM_LIBRARY}
            )
endif()
#
#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})
#target_link_libraries(Disk_Analyzer ${CURSES_LIBRARIES})
#set(CMAKE_CXX_FLAGS "-lmenu")


#find_package(Curses REQUIRED)
#target_include_directories(Disk_Analyzer PRIVATE ${CURSES_INCLUDE_DIRS})
#target_link_libraries(Disk_Analyzer ${CURSES_LIBRARIES})




#target_link_libraries(lncurses ncurses)
#SET(GCC_COVERAGE_COMPILE_FLAGS "lform -lncurses")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lform -lncurses")

