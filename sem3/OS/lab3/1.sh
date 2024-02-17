#!/bin/bash

data=$(date +"%F")
Vremya=$(date +"%H:%M:%S")

mkdir ~/test && echo "catalog test was created successfully" > ~/report ; touch ~/test/"$data"_"$Vremya"

sait=http://www.net_nikogo.ru/

ping $sait || echo "$data"_"$Vremya" "Cannot access site $sait for an unknown reason" >> ~/report
