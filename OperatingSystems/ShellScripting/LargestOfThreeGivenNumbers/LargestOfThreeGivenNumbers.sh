#!/bin/bash

A=$1
B=$2
C=$3

if [ $A -gt $B ]; then
	if [ $A -gt $C ]; then
		echo $A
	else
		echo $C
	fi
else
	if [ $B -gt $C ]; then
		echo $B
	else
		echo $C
	fi

fi
