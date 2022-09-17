/*
	O programa realiza a apresentação do currículo de um curso.
	As informações das disciplinas são lidas à partir da entrada padrão (neste caso, por indereção de arquivos).
	Uma linha será impressa para cada disciplina, com as informações devidamente formatadas. No fim, a carga horário total será imprimida.

	Daniel Gonçalves 2022
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int
main()
{

	int periodo = 0; // periodo da disciplina
	int codigo = 0; // codigo da disciplina
	char nome[31] = ""; // nome da disciplina
	int carga = 0;  // carga horária da disciplina 
	int total = 0; // carga horária total
	char codigoFinal[9] = ""; // codigo da disciplina determinado pelo programa
	char codigoNumTemp[4] = ""; // codigo numerico da disciplina temporario

	while( scanf("%d %d %[^,], %d",&periodo, &codigo, nome, &carga) != EOF)
	{
		if(codigo % 2 == 0)
		{
			strcpy(codigoFinal, "GBC");
		}
		else
		{
			strcpy(codigoFinal, "FACOM");
		}
		
		sprintf(codigoNumTemp, "%03d", codigo);
		strcat(codigoFinal, codigoNumTemp);
	
		total += carga;
		
		printf("%d \t%-10s %-35s %d\n",periodo, codigoFinal, nome, carga);
	}

	printf("Total: %d\n",total);

	return 0;
}
