#include<stdio.h>

union quantidade
{
	int unidades;
	float volume;
};

int main()
{
	union quantidade teste;
	
	printf("%ld\n",sizeof(union quantidade));
	
	teste.unidades = 10;
	printf("%d\n",teste.unidades);
	teste.volume = 5.0;
	printf("%.2f\n",teste.volume);
	printf("%d\n",teste.unidades);

	return 0;
}
