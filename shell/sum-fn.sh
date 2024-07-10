#!/usr/bin/bash

# Sum of 2 numbers using function
echo "Enter a and b"
read a
read b
sum=0

add () {
  sum=`expr $1 + $2`
}

add $a $b

echo "Sum: $sum"
