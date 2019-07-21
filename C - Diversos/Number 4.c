#include<stdio.h>
#include<stdlib.h>

float notas[4];
int i,soma=0;
float median,media_geral;

void nota()
{
    for(i=0;i<4;i++)
	{
		scanf("%f",&notas[i]);
	}
}
float media()
{
	for(i=0;i<4;i++)
	{
		soma=soma+notas[i];
		median=soma/4;
	}
	return median;
}
void aprovacao()
{
	if(media_geral>=60)
		printf("O aluno foi aprovado\n");
	else
		printf("O aluno foi reprovado\n");
}

int main()
{
	nota();
	media_geral=media();
	aprovacao();
	
    return 0;
}
