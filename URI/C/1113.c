#include<stdio.h>
#include<stdlib.h>

	int a,b;

void main(){
	for(;;){
		scanf("%d %d",&a,&b);
		if(a>b)
			printf("Decrescente\n");
		if(a<b)
			printf("Crescente\n");
		if(a==b)
			break;
	}
}
