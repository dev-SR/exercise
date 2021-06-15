#!/bin/bash;
clear
echo -n "Enter n1:"
read n1
# 
read -sp  "Enter n2:" n2
# sum=$(( $n1 + $n2 ))
sum=`expr $n1 + $n2`
echo
echo
echo
# echo into file
echo "Your sum is" $sum > file.txt
cat file.txt
pwd
ls -a
