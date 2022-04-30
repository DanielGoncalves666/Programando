#include<stdio.h>
#include"PDE.h"

int main()
{
	Pilha teste = criaPilha();

	printf("vazio %d\n", pilhaVazia(teste));
	//printf("cheia %d\n", pilhaCheia(teste));

	int i, elem;
	
	push(&teste,1);
	push(&teste,2);	
	push(&teste,3);
	push(&teste,4);
	
	printf("removido %d ",leTopo(teste,&elem));
	printf("%d\n",elem);
	
	i = 0;
	while(pop(&teste,&elem) == 1)
	{
		printf("%d\n", elem);
		i++;
	}

	return 0;
}
