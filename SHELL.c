/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
2) Write a shell script to accept and display the data through command line Arguments.
#!/bin/bash
#this is the the first shellscript
echo "Enter Your Name"
read name
echo "Enter Your Age"
read age
echo "$name is $age old"
 
3) Write a shell script to accept array element and print it in Ascending Order
#!/bin/bash

echo "size"
read n
echo " arr"
for ((i = 0; i < n; i++)) do
        read arr[i]
        
done

for ((i = 0;i<n-1;i++)) do
for ((j = 0;j < n -i-  1;j++)) do
   
   if [ ${arr[j]} -gt ${arr[j+1]} ]; then
   
   temp=${arr[j]}
   arr[j]=${arr[j+1]}
   arr[j+1]=$temp
   
   fi
   done
   done
   
 echo " arr is ${arr[@]}"
