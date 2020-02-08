#!/bin/bash

function comparar(){
	if [ $1 -qt $2 ]
	then
		echo "O maior número é $1"
	elif [ $1 -lt $2 ]
	then
		echo "O maior número é $2"
	else
		echo "Os números são iguais"
	fi
}

comparar $1 $2
soma=$[$1+$2]
echo "A soma é $soma"


