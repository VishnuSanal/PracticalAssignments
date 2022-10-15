#!/bin/bash

N=$1

PREV=1
CURRENT=0
NEXT=1

for (( I=0; I < N; I++ )); do 

    echo -n "$CURRENT "
    PREV=$CURRENT
    CURRENT=$NEXT
    NEXT=$(($PREV + $CURRENT))

done

echo
