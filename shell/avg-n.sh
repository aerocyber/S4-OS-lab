#!/usr/bin/bash

# Average of n natural numbrs

echo "Enter n"
read n
sum=0

for (( i=0; i<=$n; i++ ))
do
  sum=`expr $sum + $i`
done


avg=`expr $sum / $n`

echo "Average: $avg"
