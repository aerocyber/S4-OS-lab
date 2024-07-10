#!/usr/bin/bash


# Swap variables

read -p "Var1: " n1
read -p "Var2: " n2


echo -e "Var1: $n1 \nVar2: $n2"

n3=$n1
n1=$n2
n2=$n3

echo -e "Var1: $n1 \nVar2: $n2"
