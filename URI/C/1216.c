#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char nome[1000];
	int num, qtd = 0;
	double media;

	while(scanf("%[^\n]s",nome) != EOF){
		scanf("%d",&num);
		getchar();

		qtd++;
		media += num;
	}

	printf("%.1lf\n",media/qtd);

	return 0;
}