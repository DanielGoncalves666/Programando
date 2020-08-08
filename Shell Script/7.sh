#!/bin/bash

if [ -d $1 ]
then
	for item in $1/*			#semelhante ao for do python
	do
		if [ -d "$item" ]
		then
			echo "$item (dir)"
		else
			echo "$item"
		fi
		
	done
else
	echo "Esse diretório não existe"
fi
