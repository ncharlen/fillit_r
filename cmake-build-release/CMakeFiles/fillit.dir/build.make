# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dark/CLionProjects/fillit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dark/CLionProjects/fillit/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/fillit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fillit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fillit.dir/flags.make

CMakeFiles/fillit.dir/main.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fillit.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/main.c.o   -c /Users/dark/CLionProjects/fillit/main.c

CMakeFiles/fillit.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/main.c > CMakeFiles/fillit.dir/main.c.i

CMakeFiles/fillit.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/main.c -o CMakeFiles/fillit.dir/main.c.s

CMakeFiles/fillit.dir/field.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/field.c.o: ../field.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/fillit.dir/field.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/field.c.o   -c /Users/dark/CLionProjects/fillit/field.c

CMakeFiles/fillit.dir/field.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/field.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/field.c > CMakeFiles/fillit.dir/field.c.i

CMakeFiles/fillit.dir/field.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/field.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/field.c -o CMakeFiles/fillit.dir/field.c.s

CMakeFiles/fillit.dir/figure.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/figure.c.o: ../figure.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/fillit.dir/figure.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/figure.c.o   -c /Users/dark/CLionProjects/fillit/figure.c

CMakeFiles/fillit.dir/figure.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/figure.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/figure.c > CMakeFiles/fillit.dir/figure.c.i

CMakeFiles/fillit.dir/figure.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/figure.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/figure.c -o CMakeFiles/fillit.dir/figure.c.s

CMakeFiles/fillit.dir/main_algorithm.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/main_algorithm.c.o: ../main_algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/fillit.dir/main_algorithm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/main_algorithm.c.o   -c /Users/dark/CLionProjects/fillit/main_algorithm.c

CMakeFiles/fillit.dir/main_algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/main_algorithm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/main_algorithm.c > CMakeFiles/fillit.dir/main_algorithm.c.i

CMakeFiles/fillit.dir/main_algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/main_algorithm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/main_algorithm.c -o CMakeFiles/fillit.dir/main_algorithm.c.s

CMakeFiles/fillit.dir/fill_print_final_result.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/fill_print_final_result.c.o: ../fill_print_final_result.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/fillit.dir/fill_print_final_result.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/fill_print_final_result.c.o   -c /Users/dark/CLionProjects/fillit/fill_print_final_result.c

CMakeFiles/fillit.dir/fill_print_final_result.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/fill_print_final_result.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/fill_print_final_result.c > CMakeFiles/fillit.dir/fill_print_final_result.c.i

CMakeFiles/fillit.dir/fill_print_final_result.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/fill_print_final_result.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/fill_print_final_result.c -o CMakeFiles/fillit.dir/fill_print_final_result.c.s

CMakeFiles/fillit.dir/validate.c.o: CMakeFiles/fillit.dir/flags.make
CMakeFiles/fillit.dir/validate.c.o: ../validate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/fillit.dir/validate.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fillit.dir/validate.c.o   -c /Users/dark/CLionProjects/fillit/validate.c

CMakeFiles/fillit.dir/validate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fillit.dir/validate.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dark/CLionProjects/fillit/validate.c > CMakeFiles/fillit.dir/validate.c.i

CMakeFiles/fillit.dir/validate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fillit.dir/validate.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dark/CLionProjects/fillit/validate.c -o CMakeFiles/fillit.dir/validate.c.s

# Object files for target fillit
fillit_OBJECTS = \
"CMakeFiles/fillit.dir/main.c.o" \
"CMakeFiles/fillit.dir/field.c.o" \
"CMakeFiles/fillit.dir/figure.c.o" \
"CMakeFiles/fillit.dir/main_algorithm.c.o" \
"CMakeFiles/fillit.dir/fill_print_final_result.c.o" \
"CMakeFiles/fillit.dir/validate.c.o"

# External object files for target fillit
fillit_EXTERNAL_OBJECTS =

fillit: CMakeFiles/fillit.dir/main.c.o
fillit: CMakeFiles/fillit.dir/field.c.o
fillit: CMakeFiles/fillit.dir/figure.c.o
fillit: CMakeFiles/fillit.dir/main_algorithm.c.o
fillit: CMakeFiles/fillit.dir/fill_print_final_result.c.o
fillit: CMakeFiles/fillit.dir/validate.c.o
fillit: CMakeFiles/fillit.dir/build.make
fillit: CMakeFiles/fillit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable fillit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fillit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fillit.dir/build: fillit

.PHONY : CMakeFiles/fillit.dir/build

CMakeFiles/fillit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fillit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fillit.dir/clean

CMakeFiles/fillit.dir/depend:
	cd /Users/dark/CLionProjects/fillit/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dark/CLionProjects/fillit /Users/dark/CLionProjects/fillit /Users/dark/CLionProjects/fillit/cmake-build-release /Users/dark/CLionProjects/fillit/cmake-build-release /Users/dark/CLionProjects/fillit/cmake-build-release/CMakeFiles/fillit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fillit.dir/depend

