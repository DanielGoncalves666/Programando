#include<stdio.h>
#include<stdlib.h>

int N, C, letra;
char str[51];

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%s %d",str,&C);
		for(int h=0;;h++){
			if(str[h] == '\0'){
				printf("\n");
				break;
			}
			letra = (int) str[h];
			letra -= C;
			if(letra < 65)
				letra +=26;
			printf("%c", (char) letra);
		}
	}

	return 0;
}
