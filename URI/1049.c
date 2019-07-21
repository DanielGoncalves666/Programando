#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	char string[21];

int main(){
	scanf("%s",string);
	if(strcmp(string,"vertebrado")==0){
		scanf("%s",string);
		if(strcmp(string,"ave")==0){
			scanf("%s",string);
			if(strcmp(string,"carnivoro")==0){
				printf("aguia\n");
			}
			if(strcmp(string,"onivoro")==0){
				printf("pomba\n");
			}
		}
		if(strcmp(string,"mamifero")==0){
			scanf("%s",string);
			if(strcmp(string,"onivoro")==0){
				printf("homem\n");
			}
			if(strcmp(string,"herbivoro")==0){
				printf("vaca\n");
			}
		}
	}
	if(strcmp(string,"invertebrado")==0){
		scanf("%s",string);
		if(strcmp(string,"inseto")==0){
			scanf("%s",string);
			if(strcmp(string,"hematofago")==0){
				printf("pulga\n");
			}
			if(strcmp(string,"herbivoro")==0){
				printf("lagarta\n");
			}
		}
		if(strcmp(string,"anelideo")==0){
			scanf("%s",string);
			if(strcmp(string,"hematofago")==0){
				printf("sanguessuga\n");
			}
			if(strcmp(string,"onivoro")==0){
				printf("minhoca\n");
			}			
		}
	}

	return 0;
}
