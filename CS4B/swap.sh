#! /bin/bash

read -p "Enter the first number : " a
read -p "Enter the second number : " b

temp=$a
a=$b
b=$temp

echo "Swapped"
echo "first number : $a"
echo "second number : $b"
