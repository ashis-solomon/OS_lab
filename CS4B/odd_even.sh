#! /bin/bash

read -p "Enter the number : " num


if [ $((num%2)) -eq 0 ]
then
echo "$num is Even !!"
else
echo "$num is Odd !!"

fi
