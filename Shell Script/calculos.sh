#!/bin/bash

var=$[2+6]	#para fazermos calculos usamos $[ conteudo ]
var1=$[$var + 2]

echo $var1

#para números de ponto flutuante este método não funciona corretamente, devemos usar a calculadora do bash, a bc

exit 6		#retorna o status de retorno que for especificado
		#variáveis podem ser usadas
