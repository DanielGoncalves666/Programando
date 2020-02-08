#!/bin/bash

#a varável de ambiente IFS define os separados para a lista

for comida in pastel pizza esfiha 'pao de queijo'
do
	echo "Adoro $comida"
done

:<<"COMENT"
IFS=$'\n'	caso for alterar o caractere que separa os itens da list
COMENT

for item in /home/daniel/*
do
	if [ -d "$item" ]
	then
		echo "O item $item é um diretório"
	elif [ -f "$item" ]
	then
		echo "O item $item é um arquivo"
	fi
done
