CC=gcc
CFLAGS=-ansi -Wall -pedantic -g
LFLAGS=
TARGETS=personlist portable
HEADERS=*.h

all:$(TARGETS)

personlist:personlist.o list.o safemalloc.o
	$(CC) $(LFLAGS) $^ -o $@

personlist.o:personlist.c list.h safemalloc.h
	$(CC) $(CFLAGS) -c personlist.c

%.o:%.c $(HEADERS)
	gcc $(CFLAGS) -c $^

portable: portable.c
	gcc $(CFLAGS) $(LFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm -f *.o personlist *~