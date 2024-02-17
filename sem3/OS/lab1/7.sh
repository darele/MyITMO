#!/bin/bash

grep -o -E "[[:space:]]*([0-9]|[a-z]|[A-Z])+@([0-9]|[a-z]|[A-Z])+\.([0-9]|[a-z]|[A-Z])+(/.([0-9]|[a-z]|[A-Z])+)?[[:space:]]*" $(find /etc/ -type f) | awk 'BEGIN {FS=":"} {print $2}' > email.lst

cat email.lst | sort | uniq >> mix.txt
cat mix.txt > email.lst

rm mix.txt