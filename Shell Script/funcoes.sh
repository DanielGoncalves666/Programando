#!/bin/bash

:<<"COMENTARIO"
podemos declarar funções de duas formas:
funcao(){
}

function funcao(){
}
COMENTARIO

function olaMundo(){
	echo "Ola Mundo!"
}
#olaMundo	#chama a função

minhaFuncao(){
	echo "Eu escrevo em $2 $1"
}
#minhaFuncao $1 $2	#passando parâmetros (são inseridos via terminal), neste caso ocorrerá a inversão na ordem em que os parâmtros forem inseridos

minhaFuncao1(){
	echo "Todos os parâmetros: $@"
}
#minhaFuncao1 $@
#minhaFuncao1 $#		#mostra a quantidade de parâmtros passados

#echo $?		#se retornar 0 significa que tudo rodou de maneira correta

funcaoReturn(){
	OLA="Olá Mundo!"
	local OI="Oi Mundo!"
	echo "Estou aprendendo $@"
	return		#tudo depois do return n é executado
}
#funcaoReturn $@
#echo $OLA	#mesmo tendo sido declarada dentro da função, podemos imprimi-la
#echo $OI	#como usamos 'local' ela nao pode ser exibida fora da função





