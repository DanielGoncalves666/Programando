#include<stdio.h>
#include"DDE-DE.h"

int main()
{
	Deque teste = criaDeque();

	printf("vazio %d\n", dequeVazio(teste));
	//printf("cheia %d\n", dequeCheio(teste));

	int i, elem;
	
	insereInicio(teste,1);
	insereFinal(teste,2);	
	insereInicio(teste,3);
	insereFinal(teste,4);
	
	// 3 1 2 4
	
	i = 0;
	while(removeInicio(teste,&elem) == 1)
	{
		printf("%d\n", elem);
		i++;
	}

	return 0;
}
