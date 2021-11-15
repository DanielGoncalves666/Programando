#include<stdio.h>
#include<stdlib.h>

unsigned long long P;

int main(){
	for(;;){
		scanf("%llu",&P);
		if(P==-1)
			break;
		if(P==0)
			printf("0\n");
		else
			printf("%llu\n",P-1);	
	}
}
