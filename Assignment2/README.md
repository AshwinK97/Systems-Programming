# SOFE3200 - Assignment 2
Name: **Ashwin Kamalakannan**  
ID  : **100584423**  

These programs were compiled with gcc version 4.8.4

## Part 1 - Duplicate Utility

For part 1, we had to write a c program that can copy a file from one place to another.  

#### Process
1. Check if the correct number of arguments were given
2. Open the source file using the `open()` syscall
3. Open the destination file using the `write()` syscall
4. If destination file does not already exist, create it
5. Loop through each character in the source file and attempt to write it to the destination file
6. For each system call used, use `errno` to check for errors and display helpful messages
7. Use `signal` to trigger a message every second that the program is running
8. Display message upon completion, indicate number of bytes read and the file names

#### Compilation and Execution
1. Switch to the containing directory and type `make` to run the included Makefile
2. To execute type `./duplicate <source> <destination>`
3. If any errors occur during runtime, the program will exit with an error message

#### Output
Here is an example of the program printing errors due to incorrect inputs
![](https://i.imgur.com/53mObxo.png "example of error messages")

Here is an example of the program successfuly copying a large text file
![](https://i.imgur.com/74dqQRc.png "successfully copied file")

## Part 2 - Implement a System Call

For part 2, we had to implement a modified version of the `getpid()` syscall.
For this part, I used the linux kernal version 4.13.14 on Ubuntu 17.10.

#### Process
1. Download and extract the linux kernal to `/usr/src`
2. Change into the kernal directory and make a directory called `custom`
3. In this directory, create `noopen.c` and `noopen.h`
4. `noopen.h` will contain a function definition for `noopen(void)` and can be included in other files
5. `noopen.c` will contain a function which can be called as a system call
6. In the main linux kernal Makfile, we add `custom/` as one of the directories that contain source files to compile
7. Add a new entry to `arch/x86/entry/syscalls/syscall_32.tbl` so that the system call will exist in the list of available calls
8. Add the function definition `asmlinkage long sys_noopen(void)` to the syscalls.h file located in `include/linux`
9. Type `make oldconfig`, then `make install` to install the new kernal

I was not able to succesfully compile the modified kernal due to errors with my prior linux install. Instead, I included all of the code I used to make the syscall and give an example of how it would work.

#### Execution
1. make a test file that can access the list of available syscalls in linux
2. type `noopen()` and print its value
3. The returned value should be the process id of the current process
4. The process id should also be outputed to the terminal

#### Output
Here is an example of what the syscall's output would look like
![](https://i.imgur.com/FPHWbzX.png "example output")
