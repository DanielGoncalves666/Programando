#!/bin/bash

echo "Entre com o nome do usuário logado:"

if [ -z $1 ]
then
	echo "Digite alguma coisa pô"
elif [ $1 = "$USER" ]
then
	echo "Bem vindo $USER"
else 
	echo "Quem é vc?"
fi
