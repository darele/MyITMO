#!/bin/bash

ANS=""
while true
do
	read L
	if [[ $L == 'q' ]]
	then
		break;
	fi
	ANS=$ANS$L
done
echo $ANS