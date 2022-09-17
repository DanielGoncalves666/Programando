#include<stdio.h>

// não pode existir espaço entre o nome da macro e o parêntese dos "argumentos" dela
#define INVERTER_SINAL(num) (-1 * num)
#define SOMA(num1,num2) (num1 + num2)

int main()
{
	printf("%d\n",INVERTER_SINAL(1));
	printf("%d\n",SOMA(1,1));

	return 0;
}
