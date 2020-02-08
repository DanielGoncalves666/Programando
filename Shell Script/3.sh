#!/bin/bash

read string

if [ -d $string ]
then
	echo "Diretório"
elif [ -f $string ]
then
	echo "Arquivo"
else
	echo "Não existe"
fi
