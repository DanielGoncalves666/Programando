#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int dias, qtd, dia_atual = 1;

	scanf("%d",&dias);

	double total = 0,num, total_kg = 0.0;
	char linha[10000];

	for(int i=0; i<dias; i++){
		scanf("%lf",&num);
		getchar();
		scanf("%[^\n]s",linha);

		total += num;

		qtd = 0;
		for(int h=0; linha[h] != '\0';h++){
			if(linha[h] == ' ')
				qtd++;
		}
		qtd++;
		total_kg += qtd;

		printf("day %d: %d kg\n",dia_atual,qtd);
		dia_atual++;
	}
	printf("%.2lf kg by day\n",total_kg/dias);
	printf("R$ %.2lf by day\n",total/dias);

	return 0;
}