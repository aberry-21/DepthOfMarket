# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aberry/Desktop/DepthOfMarket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aberry/Desktop/DepthOfMarket/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/depth_of_market.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/depth_of_market.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/depth_of_market.dir/flags.make

CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o: CMakeFiles/depth_of_market.dir/flags.make
CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o: ../src/DepthOfMarket.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aberry/Desktop/DepthOfMarket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o -c /Users/aberry/Desktop/DepthOfMarket/src/DepthOfMarket.cc

CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aberry/Desktop/DepthOfMarket/src/DepthOfMarket.cc > CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.i

CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aberry/Desktop/DepthOfMarket/src/DepthOfMarket.cc -o CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.s

CMakeFiles/depth_of_market.dir/src/main.cc.o: CMakeFiles/depth_of_market.dir/flags.make
CMakeFiles/depth_of_market.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aberry/Desktop/DepthOfMarket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/depth_of_market.dir/src/main.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depth_of_market.dir/src/main.cc.o -c /Users/aberry/Desktop/DepthOfMarket/src/main.cc

CMakeFiles/depth_of_market.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depth_of_market.dir/src/main.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aberry/Desktop/DepthOfMarket/src/main.cc > CMakeFiles/depth_of_market.dir/src/main.cc.i

CMakeFiles/depth_of_market.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depth_of_market.dir/src/main.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aberry/Desktop/DepthOfMarket/src/main.cc -o CMakeFiles/depth_of_market.dir/src/main.cc.s

# Object files for target depth_of_market
depth_of_market_OBJECTS = \
"CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o" \
"CMakeFiles/depth_of_market.dir/src/main.cc.o"

# External object files for target depth_of_market
depth_of_market_EXTERNAL_OBJECTS =

depth_of_market: CMakeFiles/depth_of_market.dir/src/DepthOfMarket.cc.o
depth_of_market: CMakeFiles/depth_of_market.dir/src/main.cc.o
depth_of_market: CMakeFiles/depth_of_market.dir/build.make
depth_of_market: CMakeFiles/depth_of_market.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aberry/Desktop/DepthOfMarket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable depth_of_market"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/depth_of_market.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/depth_of_market.dir/build: depth_of_market

.PHONY : CMakeFiles/depth_of_market.dir/build

CMakeFiles/depth_of_market.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/depth_of_market.dir/cmake_clean.cmake
.PHONY : CMakeFiles/depth_of_market.dir/clean

CMakeFiles/depth_of_market.dir/depend:
	cd /Users/aberry/Desktop/DepthOfMarket/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aberry/Desktop/DepthOfMarket /Users/aberry/Desktop/DepthOfMarket /Users/aberry/Desktop/DepthOfMarket/cmake-build-debug /Users/aberry/Desktop/DepthOfMarket/cmake-build-debug /Users/aberry/Desktop/DepthOfMarket/cmake-build-debug/CMakeFiles/depth_of_market.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/depth_of_market.dir/depend

