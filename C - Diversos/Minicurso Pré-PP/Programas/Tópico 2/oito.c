#include<stdio.h>

int main()
{
	float nota1, nota2, nota3;
	float soma = 0;
	float media = 0;
	
	scanf("%f %f %f", &nota1, &nota2, &nota3);
	
	soma = nota1 + nota2 + nota3 * 2;
	media = soma / 4.0;
	
	if( media >= 60.0)
	{
		printf("Aluno aprovado com média %.2f\n", media);
	}
	else
	{
		printf("Aluno reprovado com média %.2f\n",media);
	}


	return 0;
}
