###########################################################################
# COSC1076 - Advanced Programming Techniques                              #
# Assessed lab 1 - debugging                                              #
# Created by Paul Miller                                                  #
#                                                                         #
# Makefile for the assessed lab. Simply type 'make' (no quotes) to compile#
# this project.                                                           #
###########################################################################

# The header files for this project
HEADERS=fsupport.h phone.h

# The object files that need to be built for this project
OBJECTS=fsupport.o phonebk_strtok.o

# The compiler we are using
CC=gcc

# The compiler flags to pass to gcc
CFLAGS=-ansi -Wall -pedantic

# The linker flags to pass to gcc
LFLAGS=

# The name of the executable program made by gcc
EXE=phonebk

all:$(EXE)

$(EXE): fsupport.o phonebk_strtok.o
	$(CC) $(LFLAGS) $^ -o $(EXE)
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# the debug target - if you type make debug, you will recompile your program,
# building in the debugging symbols for use with gdb and valgrind
debug:CFLAGS+=-g -DDEBUG
debug:clean $(EXE)

# this target does everything that the "debug" target above does. It also 
# compiles/links in the address sanitization library. This is a "memory 
# hardening" library that enforces strict accessing of memory addresses. 
# Any attempt to access an invalid memory address will crash your program, 
# outputting a stacktrace and additional information about the memory access
# before the crash.
sanitize:CFLAGS+=-g -DDEBUG -fsanitize=address 
sanitize:LFLAGS+=-fsanitize=address
sanitize:clean all 

.PHONY:clean
clean:
	rm -f $(EXE) *.o
zip:	
	zip -r assessedlabs22014 *.c *.h Makefile solution

