#!/bin/bash

if [ -e $1 ]
then
	if [ -d $1 ]
	then
		echo "É um diretório"
	elif [ -f $1 ]
	then
		echo "É um arquivo"
	else
		echo "Desconhecido"
	fi
else
	echo "Este arquivo não existe"
fi
