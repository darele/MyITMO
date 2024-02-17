#!/bin/bash
#Get all processes
PROCLIST=$(ps aux | awk 'NR>1 {print $2}')
for i in $PROCLIST
do
	if test -e /proc/$i/
	then
		#Get PPID
		PARENTID=$(awk '{if ($1 == "PPid:") print $2}' /proc/$i/status)
		#ART
		SUMTIME=$(awk '{if ($1 == "se.sum_exec_runtime") print $3}' /proc/$i/sched)
		NSWITCHES=$(awk '{if ($1 == "nr_switches") print $3}' /proc/$i/sched)
		AVR=$(awk -v suma=$SUMTIME -v n=$NSWITCHES 'BEGIN {print suma/n}' | tr ',' '.')

		#Printing
		echo "ProcessID = $i" ":" "Parent_ProcessID = $PARENTID" ":" "Average_Running_Time = $AVR" >> tempfile.txt
	fi
done
sort -hk 7 tempfile.txt > processstats.txt
rm tempfile.txt