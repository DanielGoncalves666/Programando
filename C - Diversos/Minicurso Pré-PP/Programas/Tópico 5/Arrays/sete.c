#include<stdio.h>

int main()
{
	int vet1[10] = {};
	int vet2[10] = {};
	int uniao[20] = {};
	int tamanho = 0;
	int i, j, k;

	for(i = 0; i < 10; i++)
	{
		scanf("%d",&vet1[i]);
	}
	
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&vet2[i]);
	}
	
	for(i = 0; i < 10; i++) // percorre o vet1
	{
		for(j = 0; j < tamanho; j++) // percorre uniao
		{
			if(uniao[j] == vet1[i]) // verifica se uniao[j] é igual ao valor de vet1 que queremos adicionar em uniao
				break;		// se for, entao para o laço
		}
		
		if(j < tamanho) //se j não for igual a tamanho, então existe um número igual em uniao
			continue;	// se for esse o caso, passa pra iteração 
	
		uniao[tamanho] = vet1[i]; // se não houver um número igual, adiciona na uniao
		tamanho++;
	}
	
	for(i = 0; i < 10;i++)
	{
		for(j = 0; j < tamanho; j++)
		{
			if(uniao[j] == vet2[i])
				break;		
		}
		
		if(j < tamanho)
			continue;
	
		uniao[tamanho] = vet2[i];
		tamanho++;
	}

	for(i = 0; i < tamanho; i++)
	{
		printf("%d\n", uniao[i]);
	}

	return 0;
}
