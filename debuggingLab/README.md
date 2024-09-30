[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vz3SqhzF)
# Debugging Assignment

### Background and Modern Memory Managment

This assignment revolves around getting comfortable with C.
C is considered to be one of the fastest languages that isn't assembly.
C is one of most important languages in modern computer science as it is the basis of every operating system.
Which is why every person planning to develop on an operating system must know and understand C.
A weakness of C, according to modern standards, is that there are very little debugging messages and error help when a program fails.
Thus, C to many programmers is difficult as there is usually not a clear answer as to why a piece of C code fails during runtime.

This assignment here is designed to get comfortable with debugging C and further your understanding of pointers.
Most modern languages avoid the use of pointers due to the fact that initalizing memory is a solved problem.
Therefore, modern languages manage memory themselves disallowing a user to control their memory directly.
In C one must manage their memory at all times.
Memory management errors are usually not caught during compile time, they appear during runtime.
Memory management errors are the majority of runtime errors in C.
When a piece of code fails, a line number is not given and there is no indication as to what caused the error in the first place.
This assignment is designed to show you common errors when working with C by forcing you to read the C code and understand it to make changes.


### Assignment Regulations

For this assignment, you are not allowed to add any extra lines of code.
The errors within the code do not require any extra lines, one must examine the code fully and once the bug is found fix it within the same line.
While working you can add lines to help debug, but upon turn in they must be deleted.
The comments of the code are also important, if a function does not contain errors, a comment will directly state that.
No edits are needed for functions that have no errors with them.

### The Assignment

The code given is an example of a simple queue data structure in C.
There are three methods, a enqueue, a deqeue, and a node initalizer that contain bugs.
Fixing the three methods is the assignment means you are done.
This assignment will be graded on completelness, finding the bugs and fixing them means you have completed it.

There are 6 lines which are incorrect.

The output should look like,

```sh
0
0       1
0       1       2
0       1       2       3
1       2       3
2       3
3
QUEUE EMPTY
```
