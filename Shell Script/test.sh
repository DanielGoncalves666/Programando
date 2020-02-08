#!/bin/bash

#o comando teste nos permite realizar comparações lógicas

:<<"COMENTARIO"
if test condição
then
	comandos
fi
- - - - - - - -
if[ condição ]		os espaços são obrigatórios
then
	comandos
fi

	Comparações Numéricas(apenas inteiros)
-eq	equal			==
-ge	great or equal		>=
-gt	great than		>
-le	less or equal		<=
-lt	less than		<
-ne	nor equal		!=
COMENTARIO

var1=10
var2=15

if [ $var1 -gt 8 ]
then
	echo "$var1 é maior que 8"
fi

if test $var1 -eq $var2
then
	echo "valores iguais"
else
	echo "valores diferentes"
fi

:<<"COMENT"
	Comparação de Strings

=	se as strings são identicas
!=	diferentes
<	menor
>	maior
-n str		se a string tem comprimento maior que zero
-z st		se o comprimento é zero	

var=''		duas aspas simples declaram uma string vazia
COMENT

nome="daniel"
if [ $USER = $nome ]
then
	echo "Olá $nome"
else
	echo "Who are you"
fi

