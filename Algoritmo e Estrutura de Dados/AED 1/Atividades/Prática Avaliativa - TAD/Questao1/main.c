#include <stdio.h>
#include "../include/complexo.h"

int main()
{
	double real = 0;
	double imaginario = 0;
	Nr_complexo *C1 = NULL, *C2 = NULL,*C3 = NULL;
	Nr_complexo *final = NULL;

	printf("Insira tres numeros complexos, parte real e imaginaria, respectivamente:\n");
	printf("Insira o primeiro (C1) numero:\n");
	scanf("%lf %lf",&real,&imaginario);
	C1 = criar_nro(real,imaginario);

	printf("Insira o segundo (C2) numero:\n");
	scanf("%lf %lf",&real,&imaginario);
	C2 = criar_nro(real,imaginario);

	printf("Insira o terceiro (C3) numero:\n");
	scanf("%lf %lf",&real,&imaginario);
	C3 = criar_nro(real,imaginario);

	if(C1 == NULL || C2 == NULL || C3 == NULL)
	{
		printf("Erro!\n");
		return -1;
	}

	final = mult(subtracao(C1,C3),C2);

	printf("\nO resultado da operação (C1 - C3) * C2 é o número %.1lf + %.1lf i.\n", acesso_real(final), acesso_imaginario(final));

	libera_nro(&C1);
	libera_nro(&C2);
	libera_nro(&C3);
	libera_nro(&final);

	return 0;
}