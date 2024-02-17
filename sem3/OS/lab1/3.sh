#!/bin/bash

D=15

while [[ $D -ne 4 ]]
do
	echo "Welcome, please select an option:"
	echo "1. Start nano"
	echo "2. Start vi"
	echo "3. Start links"
	echo "4. Exit"
	read D
	if [[ $D -eq 1 ]]
	then
		nano
	elif [[ $D -eq 2 ]]
	then
		vi
	elif [[ $D -eq 3 ]]
	then
		links
	fi
done