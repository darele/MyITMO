#!/bin/bash

ps aux | tail -1 | awk '{print $2 $0}'