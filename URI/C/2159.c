#include<stdio.h>
#include<math.h>

int main(){
	int N;
	double menor, maior;

	scanf("%d",&N);

	menor = N / log(N);
	maior = 1.25506 * (N / log(N));

	printf("%.1lf %.1lf\n",menor,maior);

	return 0;
}