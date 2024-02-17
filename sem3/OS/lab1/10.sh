#!/bin/bash

man bash | grep -o -E "(\w|_|'|-){4,}" | sort | uniq -c | sort -bnr | head -3