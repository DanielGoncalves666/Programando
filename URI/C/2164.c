#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N;
double fibonacci;

int main(){
	scanf("%d",&N);
	fibonacci = round((pow(((1+sqrt(5))/2),N) - pow(((1-sqrt(5))/2),N))/sqrt(5));
	printf("%.1lf\n",fibonacci);

	return 0;
}
