#!/bin/bash

shopt -s extglob

echo $$ > .pid

result=1
mode="+"

tail -f pipe | 
while true
do
	read line
	echo "$line"
	case "$line" in
		\+|\*)
			mode=$line
			;;
		+([0-9]))
			result=$(echo $result$mode$line | bc)
			;;
		QUIT)
			echo "See ya soon pal"
			break
			;;
		*)
			echo "The generator is stupid"
			break
			;;
	esac
	echo $result
done

killall tail