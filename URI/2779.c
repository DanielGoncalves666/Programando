#include<stdio.h>
#include<stdlib.h>
int
main()
{
	int N, M;
	int total = 0;
	int aux;

	scanf("%d %d ",&N,&M);
	int *figurinhas = (int *) calloc(N,sizeof(int));

	for(int i = 0; i < M; i++)
	{
		scanf("%d",&aux);

		if(figurinhas[aux - 1] == 0)
		{
			figurinhas[aux - 1]++;
			total++;
		}
	}

	printf("%d\n", N - total);

	return 0;
}