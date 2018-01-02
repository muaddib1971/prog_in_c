SOURCES=gameboard.c gameio.c game.c main.c rules.c player.c
HEADERS=shared.h gameboard.h gameio.h game.h main.h rules.h player.h 
OBJECTS=gameboard.o gameio.o game.o main.o rules.o player.o
CC=gcc
CFLAGS=-ansi -Wall -Wextra -pedantic -Werror
LDFLAGS=

all:tictactoe tags

tictactoe: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

debug:CFLAGS+=-g
debug:clean all

sanitize:CFLAGS+=-g -fsanitize=address
sanitize:LDFLAGS+=-fsanitize=address
sanitize:clean all

tags:
	ctags -R .

.PHONY:clean
clean:
	rm -f *.o tictactoe tags
