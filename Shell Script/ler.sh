#!/bin/bash

:<<"COMENT"
Os valores são adicionados quando se executa o script, logo após o comando de execução
Parâmetros Posicionais
	$0 -> armazena o nome do programa(exemplo: ler.sh)
	$1 em diante -> armazenas os outros parâmtros
	$(10) -> escreve desse modo para mais de um algarismo
COMENT

echo $0
quadrado=$[ $1 * $1 ]
echo "$quadrado"

# $# exibe a quantidade de parâmtros entrados pelo usuário 
