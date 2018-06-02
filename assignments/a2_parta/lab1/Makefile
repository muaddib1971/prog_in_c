###########################################################################
# COSC1076 - Advanced Programming Techniques                              #
# Assessed lab 1 - debugging                                              #
# Created by Paul Miller                                                  #
#                                                                         #
# Makefile for the assessed lab. Simply type 'make' (no quotes) to compile#
# this project.                                                           #
###########################################################################

# The head files for this project
HEADERS=reader.h writer.h shared.h swapper.h
# The object files that need to be built for this project
OBJECTS=reader.o writer.o swapper.o
# The compiler we are using 
CC=gcc
# The compiler flags
CFLAGS=-ansi -Wall -pedantic
# The linker flags
LFLAGS=
EXE=swapper

# The default target is always first in the file - it just calls the 'EXE' 
# target
all:$(EXE)

# This target calls the linker. It links together all the object files that 
# have been compiled along with any libraries that you have included.
$(EXE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXE)

# compiles each .c file into a .o file
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# this target firstly deletes all files and recompiles them with the g flag
# to export debugging symbols into the executable and defines a constant 
# DEBUG that you can uses to test things in the program. This will come in 
# handy when using gdb or valgrind.
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

# the clean target - deletes the object files and the executable
.PHONY:clean
clean:
	rm -f *.o $(EXE)


