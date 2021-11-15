#include<stdio.h>
#include<stdlib.h>

int N;
double raiz;

double divi(int repet);

int main(){
	scanf("%d",&N);
	raiz = 3.0 + divi(N); 

	printf("%.10lf\n",raiz);
	return 0;
}

double divi(int repet){
	if(repet == 0)
		return 0;
	else
		return 1.0/(6.0 + divi(repet - 1));
}
