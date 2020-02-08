#!/bin/bash

#seu funcionamento é semelhante ao Switch Case da linguagem C

local=sala

case $local in
	quarto)
		echo "Você está no quarto";;
	sala)
		echo "Você está na sala";;
	cozinha)
		echo "Você está na cozinha";;
	*)
		echo "Você está em algum lugar da casa";;
esac
