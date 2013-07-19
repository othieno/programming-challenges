programming-challenges
======================

Solutions to some of the [programming challenges](http://www.programming-challenges.com/) I've written in my free time.
The code is relatively fast but unless specified otherwise, is not optimised for speed.


Compiling
---------
To compile the code, you will need a __C and C++ compiler__ (GCC, G++, Clang etc.) as well as __GNU Make__. If you
choose to use a compiler that isn't GCC or G++, make sure to update the __CC__ and __CXX__ makefile variables.


Execution
---------
Once compiled, you can choose to run the program while manually entering input values or you can redirect the
program's input to a sample file. Assuming you're using bash, this can be accomplished with
```bash
/path/to/program < /path/to/input
```

We can also compare a program's output with an *expected output* using
```bash
diff <(/path/to/program < /path/to/input) /path/to/output
```

where the content of the output file must match the expected output if the program were to be run
with the given input file.


Layout
------
The folders provided with this software are structured in the following manner
* __samples__ sample input and output files used to test code behavior.
* __src__ contains the source code tree.
