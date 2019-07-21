#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	char nome[20];
	double salario, montante,total;

int main(){
	scanf("%s",&nome[20]);
	scanf("%lf %lf",&salario,&montante);
	total=salario+(montante/100)*15;
	printf("TOTAL = R$ %.2lf\n",total);
	
	return 0;
}
