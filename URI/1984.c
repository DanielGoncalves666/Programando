#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[20];

int main(){
	scanf("%s",string);
	for(int i=strlen(string)-1;i>=0;i--){
		printf("%c",string[i]);
	}
	printf("\n");

	return 0;
}
