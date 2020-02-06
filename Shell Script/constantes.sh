#!/bin/bash

declare -r MinhaConstante="SempreIgual"
#constantes não podem ser alteradas

echo $MinhaConstante

source funcoes.sh	#ele inclui um arquivo externo dentro do script
			#se ouvir echo no corpo do codigo eles serao executados	
olaMundo

ls(){
	echo "OI"
}
ls	#o programa da preferencia pra minha função
builtin ls ~/Documentos/Programando	#utilizamos o builtin para usarmos o comando original

