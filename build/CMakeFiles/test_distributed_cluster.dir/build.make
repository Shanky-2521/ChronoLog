# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shashankcuppala/Desktop/ChronoLog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shashankcuppala/Desktop/ChronoLog/build

# Include any dependencies generated for this target.
include CMakeFiles/test_distributed_cluster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_distributed_cluster.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_distributed_cluster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_distributed_cluster.dir/flags.make

CMakeFiles/test_distributed_cluster.dir/codegen:
.PHONY : CMakeFiles/test_distributed_cluster.dir/codegen

CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o: CMakeFiles/test_distributed_cluster.dir/flags.make
CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o: /Users/shashankcuppala/Desktop/ChronoLog/tests/test_distributed_cluster.cpp
CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o: CMakeFiles/test_distributed_cluster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o -MF CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o.d -o CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o -c /Users/shashankcuppala/Desktop/ChronoLog/tests/test_distributed_cluster.cpp

CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shashankcuppala/Desktop/ChronoLog/tests/test_distributed_cluster.cpp > CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.i

CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shashankcuppala/Desktop/ChronoLog/tests/test_distributed_cluster.cpp -o CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.s

# Object files for target test_distributed_cluster
test_distributed_cluster_OBJECTS = \
"CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o"

# External object files for target test_distributed_cluster
test_distributed_cluster_EXTERNAL_OBJECTS =

test_distributed_cluster: CMakeFiles/test_distributed_cluster.dir/tests/test_distributed_cluster.cpp.o
test_distributed_cluster: CMakeFiles/test_distributed_cluster.dir/build.make
test_distributed_cluster: libchronolog_lib.a
test_distributed_cluster: CMakeFiles/test_distributed_cluster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_distributed_cluster"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_distributed_cluster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_distributed_cluster.dir/build: test_distributed_cluster
.PHONY : CMakeFiles/test_distributed_cluster.dir/build

CMakeFiles/test_distributed_cluster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_distributed_cluster.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_distributed_cluster.dir/clean

CMakeFiles/test_distributed_cluster.dir/depend:
	cd /Users/shashankcuppala/Desktop/ChronoLog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shashankcuppala/Desktop/ChronoLog /Users/shashankcuppala/Desktop/ChronoLog /Users/shashankcuppala/Desktop/ChronoLog/build /Users/shashankcuppala/Desktop/ChronoLog/build /Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles/test_distributed_cluster.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_distributed_cluster.dir/depend

