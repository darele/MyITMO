#!/bin/bash

A=$1
B=$2
C=$3
M=$A
if [[ $B -gt $M ]]
then
	M=$B
fi
if [[ $C -gt $M  ]]
then
	M=$C
fi

echo $M
