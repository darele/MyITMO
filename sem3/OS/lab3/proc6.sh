#!/bin/bash

echo $$ > .pid

A=1
MODE="Slozhenye"

usr1()
{
	MODE="Slozhenye"
}

usr2()
{
	MODE="Umnozhenye"
}

to_octanovit()
{
	MODE="ostanov"
}

trap 'usr1' USR1
trap 'usr2' USR2
trap 'to_octanovit' SIGTERM

while true; 
do
	case $MODE in
	"Slozhenye")
		let A=$A+2
		;;
	"Umnozhenye")
		let A=$A*2
		;;
	"ostanov")
		echo "Stopped by SIGTERM, siiiuuuuuuuuuu"
		break
		;;
	esac
	echo $A
	sleep 1
done
