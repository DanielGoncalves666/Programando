#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gritos = 0,soma = 0;
char *string = NULL;

int main(){
	for(;;){
		string = malloc(sizeof(char)*9);
		fgets(string,8,stdin);
		
		if(string[0] == 'c'){
			gritos++;
			printf("%d\n",soma);
			soma = 0;
			if(gritos == 3)
				break;
		}else{
			if(string[0] == '*')
				soma += 4;
				
			if(string[1] == '*')
				soma += 2;
				
			if(string[2] == '*')
				soma +=1;
		}
		
		free(string);
	}

	return 0;
}
