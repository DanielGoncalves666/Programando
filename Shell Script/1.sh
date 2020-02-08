#!/bin/bash

read a
read b

if [ $a -eq $b ]
then
	echo "Iguais"
elif [ $a -gt $b ]
then
	echo "O primeiro é maior"
else
	echo "O segundo é maior"
fi
