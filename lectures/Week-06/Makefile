CFLAGS=-ansi -Wall -pedantic -Wextra -Werror -g
LFLAGS=
OUTPUT=add_spaces every_other phonebk_strtok phonebk_sscanf backwards envir \
convert reader

all:$(OUTPUT)

add_spaces: add_spaces.o fsupport.o
	gcc $(LFLAGS) add_spaces.o fsupport.o -o add_spaces

every_other: every_other.o fsupport.o
	gcc $(LFLAGS) every_other.o fsupport.o -o every_other

phonebk_strtok:phonebk_strtok.o fsupport.o
	gcc $(LFLAGS) phonebk_strtok.o fsupport.o -o phonebk_strtok

phonebk_sscanf:phonebk_sscanf.o fsupport.o
	gcc $(LFLAGS) phonebk_sscanf.o fsupport.o -o phonebk_sscanf

backwards:backwards.o fsupport.o
	gcc $(LFLAGS) backwards.o fsupport.o -o backwards

envir: envir.c
	gcc $(CFLAGS) $(LFLAGS) envir.c -o envir

convert: convert.o fsupport.o
	gcc $(LFLAGS) convert.o fsupport.o -o convert

reader: reader.o fsupport.o
	gcc $(LFLAGS) reader.o fsupport.o -o reader

add_spaces.o:add_spaces.c fsupport.h
	gcc $(CFLAGS) -c add_spaces.c

every_other.o:every_other.c fsupport.h
	gcc $(CFLAGS) -c every_other.c

phonebk_strtok.o:phonebk_strtok.c fsupport.h phone.h
	gcc $(CFLAGS) -c phonebk_strtok.c

phonebk_sscanf.o:phonebk_sscanf.c fsupport.h phone.h
	gcc $(CFLAGS) -c phonebk_sscanf.c

backwards.o:backwards.c fsupport.h
	gcc $(CFLAGS) -c backwards.c

convert.o:convert.c fsupport.h
	gcc $(CFLAGS) -c convert.c

reader.o:reader.c fsupport.h
	gcc $(CFLAGS) -c reader.c

fsupport.o:fsupport.c fsupport.h
	gcc $(CFLAGS) -c fsupport.c

.PHONY:clean

clean:
	rm -f *.o $(OUTPUT) *~
