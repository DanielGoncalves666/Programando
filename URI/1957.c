#include<stdio.h>
#include<stdlib.h>

int num,i;
long long N;
char *ptr;

char maior10(int num);

int main(){
	scanf("%lld",&N);
	ptr = malloc(sizeof(char)*1);
	for(i=0;;){
		num = N%16;
		ptr[i] = maior10(num);
		
		N = N/16;
		if(N == 0){
			break;	
		}
		i++;
		ptr = realloc(ptr,sizeof(char)*(i+1));		
	}
	
	for(int h=i;h>=0;h--){
		printf("%c",ptr[h]);
	}
	printf("\n");

	free(ptr);
	return 0;
}

char maior10(int num){
	switch(num){
		case 10:
			return 'A';
			break;
		case 11:
			return 'B';
			break;
		case 12:
			return 'C';
			break;		
		case 13:
			return 'D';
			break;		
		case 14:
			return 'E';
			break;		
		case 15:
			return 'F';
			break;		
		default:
			return num + '0';
			break;		
	}
}
