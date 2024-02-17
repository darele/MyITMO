#!/bin/bash

A=$(pwd)
if [[ $A == $HOME ]]
then
	exit 0
else
	echo "An internal error ocurred :'("
	exit 1
fi