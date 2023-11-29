/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//for operating system Write a program demonstrating use of different system calls (Implementation of
//Any 2 to 3 System calls.)
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
   int fd;
   char *message = "Hello, world!\n";
   
   // Open the file
   fd = open("output.txt", O_CREAT | O_WRONLY, 0644);
   if (fd < 0) {
      perror("open");
      exit(1);
   }
   
   // Write the message to the file
   if (write(fd, message, strlen(message)) < 0) {
      perror("write");
      exit(1);
   }
   
   // Close the file
   if (close(fd) < 0) {
      perror("close");
      exit(1);
   }
  
return 0;
}