The purpose of this program is to swap the contents of two
files so that the first file has the contents of the second
file and vice-versa.

So, you should be able to run this program as follows: 

./swapper first.txt second.txt

and have the contents of the two files swapped.

That's how it's supposed to work but there are a range of
bugs in this code.  There are some fatal errors in the code
but also some bugs in the code that simply cause
inappropriate or incorrect behaviour.

Your task is to find these bugs. You may use gdb, valgrind
and splint or any other tool to help you in this task. These
tools were covered in a previous lab, so look up those notes
if you are struggling with this.  While you are working
through this task, keep notes on what you are doing so
that when your marker comes by you can explain to them
what you have done.

We have provided you with a Makefile and so to compile your
program, you just need to type 'make' in the same directory
as the .c and .h files.

You are able to use resources online, those available in
blackboard and elsewhere. The only limitation is that you
need to solve the bugs yourself.

I have provided a correctly running executable called
"right_swapper" which you can compare to your executable
in terms of behaviour when thinking about bugs in the
program.
