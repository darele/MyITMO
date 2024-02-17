#!/bin/bash

shopt -s extglob

while true
do
	read line
	echo "$line" > pipe
	case "$line" in
		\+|\*|+([0-9]))
			echo "Hola Mundo"
			;;
		QUIT)
			break
			;;
		*)
			echo "The user is stupid"
			break
			;;
	esac
done
echo "0" > pipe