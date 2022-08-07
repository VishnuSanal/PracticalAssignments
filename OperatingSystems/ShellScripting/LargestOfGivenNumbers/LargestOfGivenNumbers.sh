#!/bin/bash

READ=$*

LARGEST=$1

for TOKEN in $READ
do
	if [ $TOKEN -gt $LARGEST ];
	then
		LARGEST=$TOKEN
	fi
done

echo $LARGEST
