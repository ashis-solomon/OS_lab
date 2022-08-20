#! /bin/bash

read -p "Enter the first number : " a
read -p "Enter the second number : " b

echo "sum = $((a+b))"

if [ $a -gt $b ]
then
echo "$a is greater than $b"
fi
