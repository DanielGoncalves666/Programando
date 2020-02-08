#!/bin/bash
#o comando until funciona enquanto receber um status diferente de zero

aba=10

until [ $aba -eq 0 ]
do
	echo $aba
	aba=$[ $aba - 1 ]
done  
