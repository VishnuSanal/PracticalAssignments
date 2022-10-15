#!/bin/bash

echo 'Menu:'
echo '1. Addition'
echo '2. Subtraction'
echo '3. Multiplication'
echo '4. Division'
echo '5. Modulus'

read -p 'Enter a choice: ' C

read -p 'Enter the first number: ' A
read -p 'Enter the second number: ' B

case $C in
	1) echo `expr $A + $B`;;
	2) echo `expr $A - $B`;;
	3) echo `expr $A \* $B`;;
	4) echo `expr $A / $B`;;
	5) echo `expr $A % $B`;;
	*) echo 'Invalid choice';;
esac