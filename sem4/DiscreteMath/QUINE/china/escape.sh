#!/bin/bash

escape () {
    ANS=""
    for (( i=1; i<=$#; i++ ))
    do
        LINEPART="${@:$i:1}"
        # echo "$LINEPART"
        TEMP=$(echo "$LINEPART" | tr \* '*')
        TEMP=$(echo "$TEMP" | tr '\\' "\\\\")
        TEMP=$(echo "$TEMP" | tr \' "\\'")
        TEMP=$(echo "$TEMP" | tr \" "\\\"")
        ANS="$ANS$TEMP"
        ANS="$ANS "
    done
    echo "$ANS"
    echo "Kika"
}

TEXT='Hello World "" a
I have been called to an important mission'
echo $TEXT | while read LINE
do
    escape $LINE
done