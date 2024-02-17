#!/bin/bash

# El parametro Pss es lo mismo que Rss,
# Pero en el Rss toma en cuenta las librerias ya cargadas para diferentes procesos
# Osea, si hay dos procesos usando la misma libreria, se manifiesta el tamano completo
# para cada proceso, entonces al sumar todos esos valores, obtendriamos mas memoria de la total alojada

# En el caso de Pss, si varios procesos usan una misma libreria, le asigna una porcion proporcional a ese proceso
# Osea, si hay 5 procesos que usan esa libreria, cada proceso manifiesta |lib|/5 de memoria alojada de esa libreria
# Por eso el Pss es mas certero a la hora de calcular la memoria total alojada

PROCLIST=$(ps aux | awk 'NR>1 {print $2}')
MAYOR=0
IDP=0
for i in $PROCLIST
do
	if test -e /proc/$i/smaps
	then
		CURRMEM=$(awk 'BEGIN {total=0} {if ($1 == "Pss:") total+=$2} END {print total}' /proc/$i/smaps)
		if [[ $CURRMEM -gt $MAYOR ]]
		then
			MAYOR=$CURRMEM
			IDP=$i
		fi
	fi
done

echo "The process using the most of RAM is: " $IDP
