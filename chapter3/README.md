## Exercise

Q3.2 Write your own `dup2` function that behave the same way as the `dup2` function described in Section 3.12, without calling the `fcntl` function. Be sure to handle errors correctly.

A: `work_3_2.cpp`

Q3.6 If you open a file for read-write with the append flag, can you still read from anywhere in the file using `lseek`? Can you use `lseek` to replace existing data in the file? Write a program to verify this.

A: `work_3_6.cpp`