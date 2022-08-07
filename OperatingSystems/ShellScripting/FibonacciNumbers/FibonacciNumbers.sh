#!/bin/bash

N=$1

A=0
B=1
NEXT=0

for (( i=1; i<$N; i++ ))
do
	echo -n "$B "
	NEXT=`expr $A + $B`
	A=$B
	B=$NEXT
done

echo