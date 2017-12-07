CC=gcc
CFLAGS=-ansi -Wall -pedantic -Wextra -g
LFLAGS=
TARGETS=staticptr s_malloc s_calloc s_dbl_malloc s_realloc personlist getchars_debug getchars_nodebug

all: $(TARGETS)

staticptr: staticptr.c
	gcc $(CFLAGS) $(LFLAGS) staticptr.c -o staticptr

s_malloc:s_malloc.o safemalloc.o
	gcc $(LFLAGS) s_malloc.o safemalloc.o -o s_malloc

s_calloc:s_calloc.o safemalloc.o
	gcc $(LFLAGS) s_calloc.o safemalloc.o -o s_calloc

s_dbl_malloc:s_dbl_malloc.o safemalloc.o
	gcc $(LFLAGS) s_dbl_malloc.o safemalloc.o -o s_dbl_malloc

personlist:personlist.o list.o safemalloc.o
	gcc $(LFLAGS) personlist.o list.o safemalloc.o -o personlist

s_realloc:s_realloc.o safemalloc.o
	gcc $(LFLAGS) s_realloc.o safemalloc.o -o s_realloc

s_malloc.o:s_malloc.c safemalloc.h
	gcc $(CFLAGS) -c s_malloc.c

s_calloc.o:s_calloc.c safemalloc.h
	gcc $(CFLAGS) -c s_calloc.c

s_dbl_malloc.o:s_dbl_malloc.c safemalloc.h
	gcc $(CFLAGS) -c s_dbl_malloc.c

s_realloc.o: s_realloc.c safemalloc.h
	gcc $(CFLAGS) -c s_realloc.c

personlist.o:personlist.c list.h safemalloc.h
	gcc $(CFLAGS) -c personlist.c

list.o:list.c list.h safemalloc.h
	gcc $(CFLAGS) -c list.c

getchars_debug: CFLAGS:=$(CFLAGS) -DDEBUG
getchars_debug: getchars.c
	gcc $(CFLAGS) $(LFLAGS) $< -o $@

sanitize:CFLAGS+=-fsanitize=address
sanitize:LFLAGS+=-fsanitize=address
sanitize:clean all

getchars_nodebug: getchars.c
	gcc $(CFLAGS) $(LFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGETS) *~
