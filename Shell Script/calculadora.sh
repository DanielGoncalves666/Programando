#!/bin/bash

var1=20
var2=35
var3=`echo "scale=2;$var2/$var1" | bc`
	#passamos as variaveis e a expressao para a calculadora e o comando echo imprime o resultado, o qual é redirecionado

echo $var3

:<<"COMENTARIO"
casos os cálculos forem muito grandes:
	var1=6
	var2=5
	var3=4
	var4=`bc << EOF
		scale=4
		a1=($var1 * $var2)
		b1=($var3 + $var4)
		a1+b1		<-Essas varáveis só são assessíveis aqui dentro
		EOF
	`
	echo $var4
COMENTARIO
