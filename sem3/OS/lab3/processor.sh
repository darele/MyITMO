#!/bin/bash
(tail -f pipe) |
while true; do
 read LINE;
 case $LINE in
 QUIT)
 echo "exit"
killall tail
exit
;;
 *)
 echo $LINE
;;
 esac
done