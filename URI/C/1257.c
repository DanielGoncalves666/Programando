#include<stdio.h>
#include<stdlib.h>

int N,linhas,soma,elemento, lin;
char str[51];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&linhas);
		
		lin = 0;
		soma = 0;
		for(int h=0; h<linhas; h++){
			scanf("%s",str);
			elemento = 0;
			
			for(int j=0;;j++){
				if(str[j] == '\0')
					break;
				soma += ((int) str[j] - 65) + lin + elemento; 
				elemento++;
			}
			lin++;
		}
		printf("%d\n",soma);
	}

	return 0;
}
