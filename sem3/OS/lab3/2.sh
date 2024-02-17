#!/bin/bash

echo './1.sh ; kill tail ; kill $(pidof tail)' | at now + 1 minutes

tail -f ~/report
