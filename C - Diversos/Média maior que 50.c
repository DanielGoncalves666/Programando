#include<stdio.h>
#include<stdlib.h>

int a,b,c,d,e;
float media;

int main()
{
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	
	media=(a+b+c+d+e)/5;
	
	if(media>50)
	{
		printf("Media maior que 50");
	}
	else
	{
		printf("Media menor que 50");
	}
	return 0;
}
