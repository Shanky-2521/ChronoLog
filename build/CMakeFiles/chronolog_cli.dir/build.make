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
include CMakeFiles/chronolog_cli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chronolog_cli.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chronolog_cli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chronolog_cli.dir/flags.make

CMakeFiles/chronolog_cli.dir/codegen:
.PHONY : CMakeFiles/chronolog_cli.dir/codegen

CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o: CMakeFiles/chronolog_cli.dir/flags.make
CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o: /Users/shashankcuppala/Desktop/ChronoLog/examples/chronolog_cli.cpp
CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o: CMakeFiles/chronolog_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o -MF CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o.d -o CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o -c /Users/shashankcuppala/Desktop/ChronoLog/examples/chronolog_cli.cpp

CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shashankcuppala/Desktop/ChronoLog/examples/chronolog_cli.cpp > CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.i

CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shashankcuppala/Desktop/ChronoLog/examples/chronolog_cli.cpp -o CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.s

# Object files for target chronolog_cli
chronolog_cli_OBJECTS = \
"CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o"

# External object files for target chronolog_cli
chronolog_cli_EXTERNAL_OBJECTS =

chronolog_cli: CMakeFiles/chronolog_cli.dir/examples/chronolog_cli.cpp.o
chronolog_cli: CMakeFiles/chronolog_cli.dir/build.make
chronolog_cli: libchronolog_lib.a
chronolog_cli: CMakeFiles/chronolog_cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chronolog_cli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chronolog_cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chronolog_cli.dir/build: chronolog_cli
.PHONY : CMakeFiles/chronolog_cli.dir/build

CMakeFiles/chronolog_cli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chronolog_cli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chronolog_cli.dir/clean

CMakeFiles/chronolog_cli.dir/depend:
	cd /Users/shashankcuppala/Desktop/ChronoLog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shashankcuppala/Desktop/ChronoLog /Users/shashankcuppala/Desktop/ChronoLog /Users/shashankcuppala/Desktop/ChronoLog/build /Users/shashankcuppala/Desktop/ChronoLog/build /Users/shashankcuppala/Desktop/ChronoLog/build/CMakeFiles/chronolog_cli.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chronolog_cli.dir/depend

