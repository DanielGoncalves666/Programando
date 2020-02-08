#!/bin/bash

#o comando shift transferi a variável de $2 para $1 e descarta o valor anterior de $1 

i=1

while [ -n "$1" ]
do
	echo "O parâmetro $i tem o valor: $1"
	i=$[$i+1]
	shift
done

#quantos parâmetros forem necessários
