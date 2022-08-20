#! /bin/bash

read -p "Enter the three sides of the triangle :  " a b c

if (($a==$b && $b==$c))
then
echo "TRIANGLE IS EQUILATERAL !!"
elif (($a==$b || $b==$c || $a==$c))
then
echo "TRIANGLE IS ISOCELES !!"
else
echo "TRIANGLE IS SCALENE !!"
fi

