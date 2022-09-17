#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N,M;
char str[7];

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		scanf("%s",str);
		if(strcmp(str,"fechou") == 0)
			N++;
		
		if(strcmp(str,"clicou") == 0)
			N--;
	}
	printf("%d\n",N);

	return 0;
}
