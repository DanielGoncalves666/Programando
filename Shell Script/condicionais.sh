#!/bin/bash

#nos testes condicionais são testados a saída de um comando, seu status

:<<"COMENTARIO"
if comando			Se caso o status de saída for diferente de zero 
then				os camandos dentro do if não srão executados
	comandos
fi
- - - - - - - - - 
if comando; then
	comandos
fi
COMENTARIO

if cd /
then
	echo "Diretório Raiz Encontrado"
fi


# - - - - Condicional composto - - - - - - #

if cd /home/daniel
then
	echo "Diretório encontrado"
else
	echo "Diretório Não Encontrado"
fi

# - - - - Condicional if aninhado - - - - - #
var1="a"
var2="b"

if cd /home/daniel/Documentos/$var1
then
	echo "Diretório $var1 acessado!"
elif cd /home/daniel/Documentos/$var2
then
	echo "Diretório $var2 acessado!"
else
	echo "Nenhum diretório foi encontrado"
fi





