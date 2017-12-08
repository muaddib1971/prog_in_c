SOURCES = account.c account_list.c list.c helpers.c
HEADERS = account.h account_list.h list.h bool.h helpers.h
OBJECTS = account.o account_list.o list.o helpers.o
CC = gcc
CFLAGS = -ansi -Wall -pedantic

account_list: ${OBJECTS}
	${CC} ${OBJECTS} -o $@

%.o:%.c ${HEADERS}
	${CC} ${CFLAGS} -c $<

.PHONY:clean
clean:
	rm -f *.o account_list