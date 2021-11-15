#include<stdio.h>
#include<stdlib.h>

int main(){
	double A, B;
	int N;

	while(1){
		for(;;){
			scanf("%lf",&A);
			if(A < 0.0 || A > 10.0){
				printf("nota invalida\n");
			}else{
				break;
			}
		}

		for(;;){
			scanf("%lf",&B);
			if(B < 0.0 || B > 10.0){
				printf("nota invalida\n");
			}else{
				break;
			}
		}

		printf("media = %.2lf\n",(A+B)/2);

		for(;;){
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d",&N);

			if(N == 1 || N == 2){
				break;
			}
		}

		if(N == 2)
			break;
	}

	return 0;
}