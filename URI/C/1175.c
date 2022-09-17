#include<stdio.h>
#include<stdlib.h>

	int a[20], b[20];
	int i;

void main(){

	for(i=0;i<20;i++)
		scanf("%d", &a[i]);
	for(i=0;i<20;i++)
		b[i]=a[20-1-i];
	for(i=0;i<20;i++)
		printf("N[%d] = %d\n",i,b[i]);
}
