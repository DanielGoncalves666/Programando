#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char fon[20],trab[20];

int main()
{
	gets(fon);
	strcpy(trab,fon);
	printf("fon:%s\ntrab:%s",fon,trab);
	
	
	return 0;
	
}
