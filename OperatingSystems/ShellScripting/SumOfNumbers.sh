#!/bin/bash

N=$1

SUM=0

for (( i=0; i<$N; i++ ))
do
	read -p "Enter number: " READ
	
	SUM=`expr $SUM + $READ`
done

echo $SUM