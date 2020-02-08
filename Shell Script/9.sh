#!/bin/bash

item=0
until [ $item -eq 4 ]
do
	echo
	echo "1 - Exibir status da utilização das partições; (df -h)"
	echo "2 - Exibir relação de usuários logados; (who)"
	echo "3 - Exibir data/hora; (date)"
	read -p "Entre com sua opção:" item
	echo
	
	case $item in
		1) df -h;;
		2) who;;
		3) date;;
		4) break;;
		*) echo "Opção Indisponível";;
	esac
done
