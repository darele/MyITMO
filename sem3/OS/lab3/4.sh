#!/bin/bash

./4bg.sh &

firstpid=$!

./4bg.sh &

cpulimit -p $firstpid -l 10 &

./4bg.sh &

kill $!