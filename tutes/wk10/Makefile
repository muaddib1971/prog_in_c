SOURCES=draughts.c menu.c scoreboard.c game.c gameboard.c gamerules.c \
utility.c player.c
HEADERS=shared.h draughts.h menu.h scoreboard.h game.h gameboard.h \
gamerules.h utility.h player.h
OBJECTS=draughts.o menu.o scoreboard.o game.o gameboard.o gamerules.o \
utility.o player.o
CC=gcc
CFLAGS=-ansi -Wall -pedantic
LFLAGS=
RM=/usr/bin/rm

all:draughts

draughts:$(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $@

draughts.o:draughts.c $(HEADERS)
	$(CC) $(CFLAGS) -c draughts.c 

menu.o:menu.c $(HEADERS)
	$(CC) $(CFLAGS) -c menu.c

%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

.PHONY:clean
clean:
	@$(RM) -f *.o draughts 
