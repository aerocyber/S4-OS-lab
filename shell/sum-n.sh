#!/usr/bin/bash

# Sum of n natural numbers

echo "Enter limit"
read n
sum=0

for (( i = 0; $i < $n; i++ ))
do
  sum=`expr $sum + $i`
done

echo "Sum is $sum"
