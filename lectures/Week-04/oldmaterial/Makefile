INPUTFILE=words.txt
CFLAGS=-ansi -Wall -pedantic -g
all:bubble bubble_improved insertion selection shaker shell 

bubble:bubble.o loader.o
	gcc bubble.o loader.o -o bubble

bubble_improved:bubble_improved.o loader.o
	gcc bubble_improved.o loader.o -o bubble_improved

insertion:insertion.o loader.o
	gcc insertion.o loader.o -o insertion

selection:selection.o loader.o
	gcc selection.o loader.o -o selection

shaker:shaker.o loader.o
	gcc shaker.o loader.o -o shaker

shell:shell.o loader.o
	gcc shell.o loader.o -o shell

%.o:%.c loader.h
	gcc $(CFLAGS) $^ -c 

.PHONY:clean
clean:
	rm -f binary bump bubble bubble_improved insertion linear selection \
	self_org shaker shell *.o *.gch 
