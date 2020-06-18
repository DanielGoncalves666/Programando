#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[501];

int main(){
	fgets(string,501,stdin);

	if(strlen(string)-1 > 140){
		printf("MUTE\n");
	}else
		printf("TWEET\n");

	return 0;
}
