CFLAGS=-ansi -Wall -pedantic
LFLAGS=
CC=gcc
SOURCES=list.c personlist.c safemalloc.c
HEADERS=list.h safemalloc.h
OBJECTS=list.o personlist.o safemalloc.o

all:personlist

personlist: ${OBJECTS}
	${CC} ${LFLAGS} $^ -o $@

%.o:%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

.PHONY:clean
clean:
	rm -f ${OBJECTS} personlist
