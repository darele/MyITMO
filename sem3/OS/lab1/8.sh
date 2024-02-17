#!/bin/bash

awk 'BEGIN {FS = ":"} ; { print $3 " " $1 }' /etc/passwd > mix.txt

sort -h mix.txt