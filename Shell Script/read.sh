#!/bin/bash

#read -p "Digite sua idade:"
read -p "Digite sua idade:" nome
#o parâmtro -p é usado para podermos mostrar uma mensagem
#se uma vaiável não for especificada, o conteúdo é salva na variável de ambiente REPLY
echo "Você tem $nome anos de idade!"


echo "Digite seu nome:"
if read -t 5 nome			#-t define um timer em segundos, neste caso 5
then
	echo "Olá $nome, tudo bem?"
else
	echo "Eu não tenho o dia todo"
fi


echo "Deseja entrar com seu sobrenome? Sim/Nao"
read -n3 resposta			#define uma quantidade de caracteres para serem inseridos e o comando ja ser encerrado, sem que o enter seja pressionado

case $resposta in
	S | s)	echo "Idiota";;
	N | n)	echo "Tchau";;
	*)	echo "Que?";;
esac
	
# se acrecentarmos -s no read, oq for digitado pelo usuario n aparece

read -s	

#o comando read lê uma linha por vez de um arquivo
#break funciona da msm forma aqui
	

