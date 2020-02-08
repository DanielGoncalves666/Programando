#!/bin/bash

read -p "Insira o nome do arquivo a ser criado:" string

if [ -e $string ]
then
	echo "Um arquivo já existe com esse nome"
else
	echo "Arquivo criado" > $string.txt
	chmod 555 $string.txt
fi
