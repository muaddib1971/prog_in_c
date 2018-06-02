
###########################################################################
# COSC1076 - Advanced Programming Techniques                              #
# Assessed lab 1 - debugging                                              #
# Created by Paul Miller                                                  #
#                                                                         #
# Makefile for the assessed lab. Simply type 'make' (no quotes) to compile#
# this project.                                                           #
###########################################################################

# The header files required by this program
HEADERS=fsupport.h main.h shuffle.h

# The object files created as part of compiling the .c files.
OBJECTS=fsupport.o main.o shuffle.o

# The default compiler to compile this program
CC=gcc

# The compiler flags to use when compiling this program
CFLAGS=-ansi -Wall -pedantic

# The linker flags to use when linking this program - starts empty
LFLAGS=

# The executable program produced by this Makefile
EXE=shuffle

# The default target - simply calls the target to produce the executable
all:$(EXE)

# The linking target - requires that all the objects have been created and
# if they have not been, it creates them by executing those targets.
$(EXE): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

# The compilation target - checks if the object file exists and that its 
# modification date is at least the date of the source file. If that's not
# the case it gets compiled.
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# the debug target - if you type make debug, you will recompile your program,
# building in the debugging symbols for use with gdb and valgrind
debug:CFLAGS+=-g -DDEBUG
debug:clean all

# this target does everything that the "debug" target above does. It also 
# compiles/links in the address sanitization library. This is a "memory 
# hardening" library that enforces strict accessing of memory addresses. 
# Any attempt to access an invalid memory address will crash your program, 
# outputting a stacktrace and additional information about the memory access
# before the crash.
sanitize:CFLAGS+=-g -DDEBUG -fsanitize=address 
sanitize:LFLAGS+=-fsanitize=address
sanitize:clean all 

# The clean target that deletes all files created as part of compilation 
# and linking.
.PHONY:clean
clean:
	rm -f $(EXE) *.o *~

