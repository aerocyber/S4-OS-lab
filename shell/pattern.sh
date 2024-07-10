#!/usr/bin/bash

# Pattern:
# *
# **
# ***

echo "Enter limit"
read n


for (( i=0; i<=$n; i++ ))
do
  for (( j=0; j<i; j++ ))
  do
    echo -n "*"
  done
  echo ""
done

