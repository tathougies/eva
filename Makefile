# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /nix/store/nnvcb12xnw5mbcnw5m63vfzk03g96kik-cmake-3.15.1/bin/cmake

# The command to remove a file.
RM = /nix/store/nnvcb12xnw5mbcnw5m63vfzk03g96kik-cmake-3.15.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tathougies/Projects/eva

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tathougies/Projects/eva

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/nix/store/nnvcb12xnw5mbcnw5m63vfzk03g96kik-cmake-3.15.1/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/nix/store/nnvcb12xnw5mbcnw5m63vfzk03g96kik-cmake-3.15.1/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/nix/store/nnvcb12xnw5mbcnw5m63vfzk03g96kik-cmake-3.15.1/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tathougies/Projects/eva/CMakeFiles /home/tathougies/Projects/eva/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tathougies/Projects/eva/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named eva

# Build rule for target.
eva: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 eva
.PHONY : eva

# fast build rule for target.
eva/fast:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/build
.PHONY : eva/fast

src/primitive.o: src/primitive.cpp.o

.PHONY : src/primitive.o

# target to build an object file
src/primitive.cpp.o:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/primitive.cpp.o
.PHONY : src/primitive.cpp.o

src/primitive.i: src/primitive.cpp.i

.PHONY : src/primitive.i

# target to preprocess a source file
src/primitive.cpp.i:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/primitive.cpp.i
.PHONY : src/primitive.cpp.i

src/primitive.s: src/primitive.cpp.s

.PHONY : src/primitive.s

# target to generate assembly for a file
src/primitive.cpp.s:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/primitive.cpp.s
.PHONY : src/primitive.cpp.s

src/types.o: src/types.cpp.o

.PHONY : src/types.o

# target to build an object file
src/types.cpp.o:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/types.cpp.o
.PHONY : src/types.cpp.o

src/types.i: src/types.cpp.i

.PHONY : src/types.i

# target to preprocess a source file
src/types.cpp.i:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/types.cpp.i
.PHONY : src/types.cpp.i

src/types.s: src/types.cpp.s

.PHONY : src/types.s

# target to generate assembly for a file
src/types.cpp.s:
	$(MAKE) -f CMakeFiles/eva.dir/build.make CMakeFiles/eva.dir/src/types.cpp.s
.PHONY : src/types.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... eva"
	@echo "... test"
	@echo "... src/primitive.o"
	@echo "... src/primitive.i"
	@echo "... src/primitive.s"
	@echo "... src/types.o"
	@echo "... src/types.i"
	@echo "... src/types.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

