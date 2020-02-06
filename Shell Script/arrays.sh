#!/bin/bash

mundo=("Shell" "Bash" "Bin" "Bon")

:<<"COMENTARIO"
ou
mundo[0]="Shell"
mundo[1]="Bash"
mundo[2]="Bin"
COMENTARIO

echo $mundo		#imprime o primeiro elemento
echo ${mundo[1]}	#imprime o elemento de índice 1

echo ${mundo[*]}	#imprime todos os elementos do array, na mesma linha
			#aqui pode ser usado o @ ou *
echo ${#mundo[@]}	#imprime a quantidade de elementos

echo ${mundo[@]:1}	#imprime desde o indice selecionado(incluso) para frente
echo ${mundo[@]:1:2}	#imprime o intervalo(incluso)  


