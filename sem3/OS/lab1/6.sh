#!/bin/bash

sed -n "s/(WW)/Warning:/p" X.log > full.log
sed -n "s/(II)/Information:/p" X.log >> full.log

cat full.log