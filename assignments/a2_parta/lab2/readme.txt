The program in this directory is meant to handle a common
problem in the area of information retrieval (web search
engines).

There are words that are common in many text files and they
interfere with out ability to search for a particular
topic. Once common step required in this context is to
remove these common words - commonly called stop words.

That is what the program you are provided is SUPPOSED to do
but it has a range of bugs that need to be solved.

It is supposed to read in the contents of a stop file. It
then should read in an input file and write to the output
file only those words not in the stop list.

Your task here is to use the various debugging tools
available to you such as gdb, valgrind and splint and any other
tools available on the server this problem.

You are not required to find all the bugs in this
program. Rather, we want you to find up to five bugs. The
point here however is not whether you are familiar with the
problem of stop words. The errors that have been injected
are common C errors, not specific to the problem of stop
words.

This program should have worked if called in this way: 

./stopper input.txt stopwords.txt output.txt

I have provided the output of the correctly running program
in sample_output.txt.

I have also provided a correctly behaving program in the
executable "correct_stopper".

We have provided you with a Makefile that you may assume is 
bug-free. You may compile this program by simply typing 'make'.

You may use any resources available to you. Your teaching staff
can be a valuable resource if you are struggling with getting 
started with this task or if some of the code is unfamiliar or
unclear to you. 
