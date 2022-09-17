#include<stdio.h>
#include<stdlib.h>

	int a=0,g=0,d=0,i;

void main(){
	for(;;){
		scanf("%d",&i);
		if(i==1)
			a++;
		if(i==2)
			g++;
		if(i==3)
			d++;
		if(i==4)
			break;
	}
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n",a);
	printf("Gasolina: %d\n",g);
	printf("Diesel: %d\n",d);
}
