#!/bin/bash

if test ! -f processstats.txt
then
	bash 4.sh
fi

#Number of processes with equal PPID
N=0
#Last found PPID
LASTP=0
SUMA=0

while read LINE
do
	CURRP=$(echo $LINE | awk '{print $7}')
	AVR=$(echo $LINE | awk '{print $11}')
	if [[ $CURRP == $LASTP ]]
	then
		SUMA=$(awk "BEGIN {print $SUMA+$AVR}" | tr ',' '.')
		((N++))
	else
		M=$(awk "BEGIN {print $SUMA/$N}" | tr ',' '.')
		echo "Average_Running_Children_of_ParentID = $LASTP is $M" >> tempfile.txt
		SUMA=$AVR
		LASTP=$CURRP
		N=1
	fi
done < processstats.txt

M=$(awk "BEGIN {print $SUMA/$N}" | tr ',' '.')
echo "Average_Running_Children_of_ParentID = $LASTP is $M" >> tempfile.txt
sudo cat tempfile.txt >> processstats.txt
rm tempfile.txt