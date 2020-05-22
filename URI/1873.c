#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, casos = 0;
char str1[8], str2[8];

int compara_str(char *str1, char *str2);
int decide_ganhador(char *str1, char *str2);

int main(){
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%s %s",str1,str2);
		if(compara_str(str1,str2) == 1){
			printf("empate\n");
			continue;
		}
		if(decide_ganhador(str1,str2) == 1)
			printf("rajesh\n");
		else if(decide_ganhador(str1,str2) == 2)
			printf("sheldon\n");
	}
	
	return 0;
}

int compara_str(char *str1, char *str2){
	for(int i=0;;i++){
		if(str1[i] != str2[i])
			return 0;
			
		if(str1[i] == '\0')
			return 1;	
	}
}

int decide_ganhador(char *str1, char *str2){
	if(compara_str(str1,"tesoura") == 1){
		if(compara_str(str2,"papel") == 1 || compara_str(str2,"lagarto") == 1){
			return 1;
		}else if(compara_str(str2,"pedra") == 1 || compara_str(str2,"spock") == 1){
			return 2;
		}
	}else if(compara_str(str1,"papel") == 1){
		if(compara_str(str2,"pedra") == 1 || compara_str(str2,"spock") == 1){
			return 1;
		}else if(compara_str(str2,"tesoura") == 1 || compara_str(str2,"lagarto") == 1){
			return 2;
		}
	}else if(compara_str(str1,"pedra") == 1){
		if(compara_str(str2,"tesoura") == 1 || compara_str(str2,"lagarto") == 1){
			return 1;
		}else if(compara_str(str2,"papel") == 1 || compara_str(str2,"spock") == 1){
			return 2;
		}
	}else if(compara_str(str1,"lagarto") == 1){
		if(compara_str(str2,"papel") == 1 || compara_str(str2,"spock") == 1){
			return 1;
		}else if(compara_str(str2,"pedra") == 1 || compara_str(str2,"tesoura") == 1){
			return 2;
		}

	}else if(compara_str(str1,"spock") == 1){
		if(compara_str(str2,"pedra") == 1 || compara_str(str2,"tesoura") == 1){
			return 1;
		}else if(compara_str(str2,"lagarto") == 1 || compara_str(str2,"papel") == 1){
			return 2;
		}
	}
}
