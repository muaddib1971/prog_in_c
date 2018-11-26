SOURCES=file_funcs.c file_process.c
HEADERS=file_funcs.h file_process.h

all: file_funcs

file_funcs:file_funcs.o file_process.o
	gcc file_funcs.o file_process.o -o file_funcs

%.o:%.c ${HEADERS}
	gcc -ansi -Wall -pedantic -Wextra -Werror -c $<

.PHONY:clean
clean:
	rm -f *.o file_funcs atmom.txt.*

