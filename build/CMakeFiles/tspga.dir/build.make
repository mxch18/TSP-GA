# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build

# Include any dependencies generated for this target.
include CMakeFiles/tspga.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tspga.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tspga.dir/flags.make

CMakeFiles/tspga.dir/src/main.cpp.o: CMakeFiles/tspga.dir/flags.make
CMakeFiles/tspga.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tspga.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tspga.dir/src/main.cpp.o -c /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/main.cpp

CMakeFiles/tspga.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tspga.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/main.cpp > CMakeFiles/tspga.dir/src/main.cpp.i

CMakeFiles/tspga.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tspga.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/main.cpp -o CMakeFiles/tspga.dir/src/main.cpp.s

CMakeFiles/tspga.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/tspga.dir/src/main.cpp.o.requires

CMakeFiles/tspga.dir/src/main.cpp.o.provides: CMakeFiles/tspga.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tspga.dir/build.make CMakeFiles/tspga.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/tspga.dir/src/main.cpp.o.provides

CMakeFiles/tspga.dir/src/main.cpp.o.provides.build: CMakeFiles/tspga.dir/src/main.cpp.o


CMakeFiles/tspga.dir/src/Point.cpp.o: CMakeFiles/tspga.dir/flags.make
CMakeFiles/tspga.dir/src/Point.cpp.o: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tspga.dir/src/Point.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tspga.dir/src/Point.cpp.o -c /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Point.cpp

CMakeFiles/tspga.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tspga.dir/src/Point.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Point.cpp > CMakeFiles/tspga.dir/src/Point.cpp.i

CMakeFiles/tspga.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tspga.dir/src/Point.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Point.cpp -o CMakeFiles/tspga.dir/src/Point.cpp.s

CMakeFiles/tspga.dir/src/Point.cpp.o.requires:

.PHONY : CMakeFiles/tspga.dir/src/Point.cpp.o.requires

CMakeFiles/tspga.dir/src/Point.cpp.o.provides: CMakeFiles/tspga.dir/src/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/tspga.dir/build.make CMakeFiles/tspga.dir/src/Point.cpp.o.provides.build
.PHONY : CMakeFiles/tspga.dir/src/Point.cpp.o.provides

CMakeFiles/tspga.dir/src/Point.cpp.o.provides.build: CMakeFiles/tspga.dir/src/Point.cpp.o


CMakeFiles/tspga.dir/src/Path.cpp.o: CMakeFiles/tspga.dir/flags.make
CMakeFiles/tspga.dir/src/Path.cpp.o: ../src/Path.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tspga.dir/src/Path.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tspga.dir/src/Path.cpp.o -c /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Path.cpp

CMakeFiles/tspga.dir/src/Path.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tspga.dir/src/Path.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Path.cpp > CMakeFiles/tspga.dir/src/Path.cpp.i

CMakeFiles/tspga.dir/src/Path.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tspga.dir/src/Path.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/src/Path.cpp -o CMakeFiles/tspga.dir/src/Path.cpp.s

CMakeFiles/tspga.dir/src/Path.cpp.o.requires:

.PHONY : CMakeFiles/tspga.dir/src/Path.cpp.o.requires

CMakeFiles/tspga.dir/src/Path.cpp.o.provides: CMakeFiles/tspga.dir/src/Path.cpp.o.requires
	$(MAKE) -f CMakeFiles/tspga.dir/build.make CMakeFiles/tspga.dir/src/Path.cpp.o.provides.build
.PHONY : CMakeFiles/tspga.dir/src/Path.cpp.o.provides

CMakeFiles/tspga.dir/src/Path.cpp.o.provides.build: CMakeFiles/tspga.dir/src/Path.cpp.o


# Object files for target tspga
tspga_OBJECTS = \
"CMakeFiles/tspga.dir/src/main.cpp.o" \
"CMakeFiles/tspga.dir/src/Point.cpp.o" \
"CMakeFiles/tspga.dir/src/Path.cpp.o"

# External object files for target tspga
tspga_EXTERNAL_OBJECTS =

tspga: CMakeFiles/tspga.dir/src/main.cpp.o
tspga: CMakeFiles/tspga.dir/src/Point.cpp.o
tspga: CMakeFiles/tspga.dir/src/Path.cpp.o
tspga: CMakeFiles/tspga.dir/build.make
tspga: CMakeFiles/tspga.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tspga"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tspga.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tspga.dir/build: tspga

.PHONY : CMakeFiles/tspga.dir/build

CMakeFiles/tspga.dir/requires: CMakeFiles/tspga.dir/src/main.cpp.o.requires
CMakeFiles/tspga.dir/requires: CMakeFiles/tspga.dir/src/Point.cpp.o.requires
CMakeFiles/tspga.dir/requires: CMakeFiles/tspga.dir/src/Path.cpp.o.requires

.PHONY : CMakeFiles/tspga.dir/requires

CMakeFiles/tspga.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tspga.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tspga.dir/clean

CMakeFiles/tspga.dir/depend:
	cd /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build /home/maxens/Bureau/Stage/Code/C++/Traveling_Salesman/build/CMakeFiles/tspga.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tspga.dir/depend

