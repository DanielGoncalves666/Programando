#include <stdio.h>
#include <stdlib.h>
#include "header_8.h"

void tratamento_escolha(Polimonio lst, int escolha);

int main()
{
	Polimonio numero = inicializar();
	int escolha = 0;
	
	do
	{
		printf("\n--------- Manipulação de Polinômios ---------");
		printf("\nPor favor, entre com a opção desejada.\n");
		printf("1 - Inserir um novo termo a_k * x^k.\n");
		printf("2 - Remover o termo associado a k-ésima potencia.\n");
		printf("3 - Reinicializar o polinômio.\n");
		printf("4 - Imprimir polinômio.\n");
		printf("5 - Calcular valor do polinômio para um x qualquer.\n");
		printf("6 - Sair.\n");
		scanf("%d", &escolha);

		if(escolha == 6)
			break;
		else	
			tratamento_escolha(numero,escolha);

	}while(1);

	return 0;
}

void tratamento_escolha(Polimonio lst, int escolha)
{
	int exp, coef;
	int retorno;
	int eliminado;

	switch (escolha)
	{
		case 1:
			printf("\n----Processo de Inserção de termo----\n");
			printf("Entre com o coeficiente e o expoente da potência x:\n");
			scanf("%d %d",&coef, &exp);
			
			retorno = inserir(lst, exp, coef);
			if(retorno == 0)
				printf("\n----Falha na operação! Não foi possível inserir----\n");
			else if(retorno == 2)
				printf("\n----Coeficiente para o termo resultou em zero. O termo %d foi removido----\n",exp);
			else
				printf("\n----Operação realizada com sucesso!----\n");
			break;
		case 2:
			printf("\n----Processo de remoção de termo.----\n");
			printf("Entre com o expoente da potência de x a ser eliminada:\n");
			scanf("%d", &exp);
			
			retorno = eliminar_potencia(lst, exp, &eliminado);
			if(retorno == 0)
				printf("\n----Falha na operação! Termo não existente!----\n");
			else
				printf("\n----O termo %d^%d foi removido----\n",eliminado,exp);
			break;
		case 3:
			printf("\n\n----Reinicializando o polimônio.----\n");
			reiniciar(lst);

			break;
		case 4:
			imprimir(lst);

			break;
		case 5:
			printf("\n----Calculando valor para P(x)----\n");
			printf("Por favor, entre com o valor de x:\n");
			scanf("%d",&coef);
			
			retorno = calcular(lst, coef);
			printf("\nP(%d) = %d\n\n",coef,retorno);
			
			break;
		default:
			printf("\n\n----Opção invalida!----\n");
	}
}
