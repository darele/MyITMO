#!/bin/bash

awk '{ if($2 == "INFO") print $0;}' syslog > info.log