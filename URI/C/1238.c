#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N;
char str1[50],str2[50];

void aux(char *P, int N, int i){
	for(; i<N; i++){
		if(P[i] != '\0')
			printf("%c",P[i]);
		else
			break;
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%s",str1);
		scanf("%s",str2);
		for(int h=0;;h++){
			if(str1[h] != '\0')
				printf("%c",str1[h]);
			else{
				aux(str2,N,h);
				break;
			}
			if(str2[h] != '\0')
				printf("%c",str2[h]);
			else{
				aux(str1,N,h+1);
				break;
			}
		}
		printf("\n");
	}

	return 0;
}
