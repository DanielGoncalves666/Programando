#include<stdio.h>
#include<stdlib.h>

	double N;
	int a;

int main(){
	scanf("%lf",&N);
	printf("NOTAS:\n");
	a=N/100.00;
	N-=a*100.00;
	printf("%d nota(s) de R$ 100.00\n",a);
	a=N/50.00;
	N-=a*50.00;
	printf("%d nota(s) de R$ 50.00\n",a);
	a=N/20.00;
	N-=a*20.00;
	printf("%d nota(s) de R$ 20.00\n",a);
	a=N/10.00;
	N-=a*10.00;
	printf("%d nota(s) de R$ 10.00\n",a);
	a=N/5.00;
	N-=a*5.00;
	printf("%d nota(s) de R$ 5.00\n",a);
	a=N/2.00;
	N-=a*2.00;
	printf("%d nota(s) de R$ 2.00\n",a);
	
	printf("MOEDAS:\n");
	a=N/1.00;
	N-=a*1.00;
	N+=0.0005;
	printf("%d moeda(s) de R$ 1.00\n",a);
	a=N/0.50;
	N-=a*0.50;
	printf("%d moeda(s) de R$ 0.50\n",a);
	a=N/0.25;
	N-=a*0.25;
	printf("%d moeda(s) de R$ 0.25\n",a);
	a=N/0.10;
	N-=a*0.10;
	printf("%d moeda(s) de R$ 0.10\n",a);
	a=N/0.05;
	N-=a*0.05;
	printf("%d moeda(s) de R$ 0.05\n",a);
	a=N/0.01;
	N-=a*0.01;
	printf("%d moeda(s) de R$ 0.01\n",a);

	return 0;
}
