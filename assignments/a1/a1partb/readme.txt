Staff Name: Paul Miller
Staff Number: e70949

Compilation instructions
------------------------

On titan, jupiter or saturn issue the following command: 

gcc -ansi -Wall -pedantic main.c menu.c options.c -o cpt220_menu_system

in the same directory as this code. Alternatively you can replace all of the 
.c files with *.c.

gcc -ansi -Wall -pedantic *.c -o cpt220_menu_system

Instructions for running
-------------------------

./cpt220_menu_system [seed]

where seed is an optional long integer.

Implementation Approach
------------------------

I started with the initialisation of the menu itself. By putting these into 
an array and then copying them with memcpy, I don't need to change anything
other than the string and the enum value in order to reorder the elements of 
the menu with the right numbering. 

Roadblocks
-----------

No issues so far. But then I have written similar code many times. I do 
understand that for many of you the subtle relationship between arrays and
pointers can be a problem and the issue of when you are dealing with one or
the other can be frustrating because of the ambiguity of the language. 

Please note that I have not implemented any of the code for fgets() as if you
have not worked out that code, that is really your most urgent task. You will
need to understand that code both to complete this assignment and all components
of assignment 2. 
