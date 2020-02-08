#!/bin/bash

if [ $1 -eq 0 ]
then
	echo "Nulo"
elif [ $1 -gt 0 ]
then
	echo "Positivo"
else
	echo "Negativo"
fi
