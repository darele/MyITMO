#!/bin/bash

dir=$(pwd)

echo "*/5 * * * 2 $dir/1.sh" | crontab