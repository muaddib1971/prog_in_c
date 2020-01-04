OBJECTS=menu.o io.o main.o
HEADERS=menu.h io.h bool.h
SOURCES=menu.c io.c main.c
CFLAGS=-ansi -Wall -pedantic
LDFLAGS=
CC=gcc

all: menu

menu: $(OBJECTS)
	gcc $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

debug:CFLAGS+=-g 
debug:clean all

.PHONY:clean
clean:
	rm -f *.o menu
