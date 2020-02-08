#!/bin/bash

:<<"COMENT"
	Comparação de Arquivos
	
-d arquivo		verifica se existe e se é um diretoório
-e    ;;			;;
-f    ;; 			;; 	   e se é um arquivo
-r    ;;			;; 	   e se ṕossui permissao de leitura
-s    ;;			;;	   e se n está vazio
-w    ;;			;;	   e se tem permissao de escrita
-x    ;;			;;	   e se tem permissao de execução
-O    ;;			;;	   e se é do usuário atual
-G    ;;			;;	   e se o grupo padrao é o msm que o usuario
arq1 -nt arq2		verifica se o arq1 é mais novo que o ar2
arq1 -ot arq2		verifica se é mais velho
COMENT

if [ -d $HOME ]
then 
	echo "Diretorio existe e seu conteúdo:"
	#ls $HOME
else
	echo "Diretório não encontrado"
fi 

if test -e $HOME
then
	echo "Existe"
	if [ -f $HOME ]
	then
		echo "Arquivo"
	else
		echo "Diretório"
	fi
else
	echo "Não existe"
fi

