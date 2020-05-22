#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, F;
char string[15], thor[4] = "Thor";

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%s %d",string,&F);
		for(int h=0;;h++){
			if(string[h] == '\0'){
				printf("Y\n");
				break;
			}else if(string[h] != thor[h]){
				printf("N\n");
				break;
			}
		}
	}
	
	return 0;
}
