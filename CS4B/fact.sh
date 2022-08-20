#! /bin/bash

read -p "Enter the number : " num

fact=1
num1=$num

while [ $num -gt 1 ]
do
fact=$((fact*num))
num=$(($num-1))
done

echo "The factorial of $num1 is = $fact"
