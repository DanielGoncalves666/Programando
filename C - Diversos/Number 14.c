#include<stdio.h>
#include<stdlib.h>

float carro,pago,des;
int ano,a=0,b=0,pare;

void informacoes()
{
	printf("Digite o valor do carro:\n");
	scanf("%f",&carro);
	printf("Digite o ano do carro\n");
	scanf("%d",&ano);
}
void desconto()
{
	if(ano<=2000)
		des=(carro/100)*12;
	if(ano>2000)
		des=(carro/100)*7;
}
void valor()
{
	printf("O desconto sobre o preco desse carro sera de R$%.2f\n",des);
	pago=carro-des;
	printf("O valor pago neste carro foi de R$%.2f\n",pago);
}
void continuar()
{
	printf("Deseja continuar? Digite 0 para parar e qualquer numero para continuar.\n");
	scanf("%d",&pare);
}
void total_geral()
{
	printf("O total de carros vendidos cujo ano fosse= menor ou igual a 2000 foi de %d.\n",a);
	printf("O total geral de carros vendidos foi de %d.\n",b);
}

int main()
{
	for(;;)
	{
		informacoes();
		desconto();
		valor();
		continuar();
		if(ano<=2000)
			a++;
		b++;		
		if(pare==0)
			break;	
	}
	total_geral();
    return 0;
}
