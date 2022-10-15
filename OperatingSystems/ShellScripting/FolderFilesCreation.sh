#!/bin/bash

read -p 'Enter the folder name: ' DIR

read -p 'Enter the file prefix: ' FILE

mkdir $DIR

for ((i=0; i<5; i++))
do
	touch "$DIR/$FILE$i"
done