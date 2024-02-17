#!/bin/bash

for i in $(awk 'BEGIN {FS=":"} {print $1}' /etc/passwd)
do
    echo "Processes executed by: " $i
    ps -u $i | awk 'NR > 1 {print $1}'
done