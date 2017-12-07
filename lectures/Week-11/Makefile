CFLAGS=-ansi -Wall -pedantic -g
CC=gcc
TARGETS=gen_convert double_sort double_search wrong_swap right_swap \
	for_each_int for_each generic_list
all: $(TARGETS)

%.o:%.c *.h

generic_list: list.o genericlist.o
	$(CC) $^ -o $@
.PHONY: clean
clean:
	rm -f $(TARGETS) *.o