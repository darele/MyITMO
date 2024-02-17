#!/bin/bash

while true
do
	read line
	case "$line" in
		\+)
			echo "Slozhitelniy znak prinyat"
			kill -USR1 $(cat .pid)
			;;
		\*)
			echo "umnozhitelniy znak prinyat"
			kill -USR2 $(cat .pid)
			;;
		TERM)
			kill -SIGTERM $(cat .pid)
			echo "signal term"
			break
			;;
		*)
			echo "The user is stupid"
			;;
	esac
done