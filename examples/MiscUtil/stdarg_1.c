/** Demonstrates the use of va_list, va_arg, va_start and va_end macros that 
 *  are defined in stdarg.h header file.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/** A function that receives an unspecified number of arguments. 
 *  The ellipsis (...) indicates that the function accepts variable number
 *  of arguments.
 **/
int product(int, ...);

int main() {
   int num1 =10, num2 =20, num3 =30, num4 =40;

   printf("\n %d X %d = %d", num1, num2, 
                                        product(2, num1, num2));
   printf("\n %d X %d X %d = %d", num1, num2, num3, 
                                        product(3, num1, num2, num3));
   printf("\n %d X %d X %d X %d = %d\n", num1, num2, num3, num4,
                                        product(4, num1, num2, num3, num4));

   return(EXIT_SUCCESS);
}

int product(int size, ...) {
   int prod =1;
   int i;

   /** A va_list type variable should be declared to access the variable length
    *  of parameter list. In actual va_list is type defined as a 'char *' in 
    *  the stdarg.h
    * */
   va_list nums;

   /** Initialises the object of the va_list type -- essential to do before
    *  va_start can use it
    **/
   va_start(nums, size);

   /** The loop below multiplies each value of the variable length parameter 
    *  list and stores the product in 'prod'. Each value of the list is 
    *  extracted by a call to va_arg macro. The va_arg macro returns the 
    *  currently pointed object (in the va_list) and increments the pointer to 
    *  point it to the next object. The 2nd parameter of va_arg specifies what
    *  is teh data type of the value to be expected in the va_list. 
    **/
   for( i=0; i < size; i++) {
      prod *= va_arg(nums, int);
   }

   /** va_end performs a cleanup so that there is a normal return to the 
    *  caller function. In effect, it may simply assign zero/NULL to the
    *  va_list object.
    **/
   va_end(nums);

   return prod;
}

