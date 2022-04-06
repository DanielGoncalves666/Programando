#include<stdio.h>
#include<math.h>

float distanciaEntrePontos(int x1, int y1, int x2, int y2);

int main()
{
	int r1, r2, x1, y1, x2, y2;

	while(scanf("%d",&r1) != EOF)
	{
		scanf("%d %d %d %d %d",&x1,&y1,&r2,&x2,&y2);
		if(distanciaEntrePontos(x1,y1,x2,y2) + r2 <= r1)
		{
			printf("RICO\n");
		}
		else
		{
			printf("MORTO\n");
		}
	}

	return 0;
}

float distanciaEntrePontos(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}