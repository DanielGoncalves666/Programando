#include<stdio.h>
#include"FDE-EC.h"

int main()
{
	Fila teste = criaFila();

	printf("vazio %d\n", filaVazia(teste));
	//printf("cheia %d\n", filaCheia(teste));

	int i, elem;
	
	insereFinal(&teste,1);
	insereFinal(&teste,2);	
	insereFinal(&teste,3);
	insereFinal(&teste,4);
	
	i = 0;
	while(removeInicio(&teste,&elem) == 1)
	{
		printf("%d\n", elem);
		i++;
	}

	return 0;
}
