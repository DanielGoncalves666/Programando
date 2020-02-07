#!/bin/bash

dia=`date +%d%m%y%H%M`		# crase redireciona a saida de um determinado comando para uma variável, por exemplo
				#o restante são parâmetros para o comando date, sendo eles dia, mês, ano, hora e minutos
				
ls -la /home/daniel/Downloads > log.$dia.txt

#o comando de listagem do diretário é armazenado no arquivo log.data
#se for usado apenas > e deixarmos com q o arquivo tenha o mesmo nome ocorrerá uma sobreposição
#caso usarmos >> as informações serão adicionadas no final
# o < redireciona informações para um comando, advindas de um arquivo
# o << nos permite redirecionar informações direto do terminal
				



