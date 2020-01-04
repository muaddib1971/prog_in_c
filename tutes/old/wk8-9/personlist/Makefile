SOURCES=list.c person.c main.c
HEADERS=list.h person.h bool.h
OBJECTS=list.o person.o main.o
CC=gcc
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=-lm

all: personlist

personlist: $(OBJECTS)
	@echo "hello I will make a person list"
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

list.o:list.c list.h person.h bool.h
	gcc -ansi -Wall -pedantic -c list.c

%.o: %.c $(OBJECTS)
	$(CC) $(CFLAGS) -c $<

debug:CFLAGS+=-g -DDEBUG
debug:clean all

.PHONY:clean
clean:
	rm -f *.o personlist
