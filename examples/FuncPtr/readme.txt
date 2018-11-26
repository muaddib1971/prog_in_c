This program demonstrates how we can use function pointers to create a menu
system. 

If you look in file_funcs.h, line 27, you will see a line such as the following:

typedef void (*action)(char[]);

This defines an 'action' as a pointer to a function. This pointer to a function
returns nothing (void) and takes a char array as a parameter.

Also in the same header file we have the following struct declaration: 

struct menu_item
{
        char title[LINELEN + 1];
        action act;
};

In other words, a menu_item contains a string called the title and an action
(remember that an action was defined above as a pointer to a function that 
returns void and accepts a char array).

In the main() function which is defined in file_funcs.c, we have the 
declaration of the following array: 

struct menu_item menu_items[NUM_MENU_OPTIONS] = {
        { "shuffle each line", shuffle },
        { "save every second char", every_other },
        { "shift all chars up by one value", shift },
        { "quit", quit }
};

So, this is an array of menu items where the first element, the string 
represents the menu text and the second eleent, the function pointer (if you 
look in file_process.h, you will see functions with the names specified). 

So menu_items[N].act("filename") calls the function in the Nth index of the 
array. In your assignment you will also apply this idea to a different type 
of array. 

For that reason, it's important to understand this example and be able to 
apply it. 

The key loop in main is the following: 

for (;;)
{
        menu_result = menu(menu_items);
        menu_items[menu_result].act(FILEARG);
}

So loop forever:
    display a menu and get menu input
    run the requested operation on the array
done
