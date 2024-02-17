#!/bin/bash


GetProcessWeight() {
	PROCLIST=$(ps aux | awk 'NR>1 {print $2}')
	LINEINDEX=1
	for i in $PROCLIST
	do
		if test -e /proc/$i/io
		then
			if [[ $# -gt 1 ]]
			then
				echo $(sed -n "${LINEINDEX}p" < $2) $(awk '{if ($1 == "rchar:") print $2}' /proc/$i/io) >> $1
			else
				echo $i $(awk '{if ($1 == "rchar:") print $2}' /proc/$i/io) >> $1 
			fi
			((LINEINDEX++))
		fi
	done
	sort -hk 1 $1 > mix.txt
	cat mix.txt > $1
	rm mix.txt
}

GetProcessWeight tempInitialData.txt

# echo "Hola Mundo"

sleep 1m

# echo "ya pasaron 5 segundos"

GetProcessWeight tempFinalData.txt tempInitialData.txt

awk '{print $1 " " $3-$2}' tempFinalData.txt > mix.txt

echo "The three most busy process (in terms of disk access) are:

PID   #access in a minute"

sort -hrk 2 mix.txt | head -3

rm tempInitialData.txt
rm mix.txt
rm tempFinalData.txt