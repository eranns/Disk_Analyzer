# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/erans/CLionProjects/Disk_Analyzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Disk_Analyzer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Disk_Analyzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Disk_Analyzer.dir/flags.make

CMakeFiles/Disk_Analyzer.dir/main.cpp.o: CMakeFiles/Disk_Analyzer.dir/flags.make
CMakeFiles/Disk_Analyzer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Disk_Analyzer.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Disk_Analyzer.dir/main.cpp.o -c /Users/erans/CLionProjects/Disk_Analyzer/main.cpp

CMakeFiles/Disk_Analyzer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Disk_Analyzer.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/erans/CLionProjects/Disk_Analyzer/main.cpp > CMakeFiles/Disk_Analyzer.dir/main.cpp.i

CMakeFiles/Disk_Analyzer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Disk_Analyzer.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/erans/CLionProjects/Disk_Analyzer/main.cpp -o CMakeFiles/Disk_Analyzer.dir/main.cpp.s

CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o: CMakeFiles/Disk_Analyzer.dir/flags.make
CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o: ../src/FSFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o -c /Users/erans/CLionProjects/Disk_Analyzer/src/FSFile.cpp

CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/erans/CLionProjects/Disk_Analyzer/src/FSFile.cpp > CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.i

CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/erans/CLionProjects/Disk_Analyzer/src/FSFile.cpp -o CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.s

CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o: CMakeFiles/Disk_Analyzer.dir/flags.make
CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o: ../src/FSthreadpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o -c /Users/erans/CLionProjects/Disk_Analyzer/src/FSthreadpool.cpp

CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/erans/CLionProjects/Disk_Analyzer/src/FSthreadpool.cpp > CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.i

CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/erans/CLionProjects/Disk_Analyzer/src/FSthreadpool.cpp -o CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.s

# Object files for target Disk_Analyzer
Disk_Analyzer_OBJECTS = \
"CMakeFiles/Disk_Analyzer.dir/main.cpp.o" \
"CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o" \
"CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o"

# External object files for target Disk_Analyzer
Disk_Analyzer_EXTERNAL_OBJECTS =

Disk_Analyzer: CMakeFiles/Disk_Analyzer.dir/main.cpp.o
Disk_Analyzer: CMakeFiles/Disk_Analyzer.dir/src/FSFile.cpp.o
Disk_Analyzer: CMakeFiles/Disk_Analyzer.dir/src/FSthreadpool.cpp.o
Disk_Analyzer: CMakeFiles/Disk_Analyzer.dir/build.make
Disk_Analyzer: /usr/local/lib/libboost_filesystem-mt.dylib
Disk_Analyzer: /usr/local/lib/libboost_system-mt.dylib
Disk_Analyzer: CMakeFiles/Disk_Analyzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Disk_Analyzer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Disk_Analyzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Disk_Analyzer.dir/build: Disk_Analyzer

.PHONY : CMakeFiles/Disk_Analyzer.dir/build

CMakeFiles/Disk_Analyzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Disk_Analyzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Disk_Analyzer.dir/clean

CMakeFiles/Disk_Analyzer.dir/depend:
	cd /Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/erans/CLionProjects/Disk_Analyzer /Users/erans/CLionProjects/Disk_Analyzer /Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug /Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug /Users/erans/CLionProjects/Disk_Analyzer/cmake-build-debug/CMakeFiles/Disk_Analyzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Disk_Analyzer.dir/depend
