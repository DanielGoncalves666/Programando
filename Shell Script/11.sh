#!/bin/bash

read -p "Entre o primeiro número: " n1
read -p "Entre o segundo número: " n2
read -p "Entre o terceiro número: " n3

if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
	echo "O maior número é o primeiro"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
	echo "O maior número é o segundo"
else
	echo "O maior número é o terceiro"
fi
