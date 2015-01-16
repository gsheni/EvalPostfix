EvalPostfix
==============

This EvalPostfix program will read in command line arguments that correspond to a postfix expression. Each number and operator in the expression is expected to be space delimited.

The following conditions must be fulfilled
- The expression needs to have positive integers and atomico operators (+,-,*,/) as well as left and right parentheses.   
- For *, you a backslash must be preceded.  
-	The first command line argument is either a positive integer 

Program will thrown and error in the following cases
- When there is no command line arguments.
- There will be an error when there is an operator that is not one of the atomic ones listed above.

Example Input Expressions:
```txt
$ 2 3 + 

$ 3 5 \* 

$ 4 2 / 

$ 6 3 9 + \* 

$ 7 3 - 2 \* 

$ 6 5 2 - 4 + \* =

$	1 2 + 3 \* 4 + 5 \* 
```
The output of the program will be the answer of the computation.

If there is an error in the input, the output will be a blank line.
