#include<stdio.h>
#include<stdlib.h>

	float a,b,media;

int main(){
	for(;;){
		scanf("%f",&a);
		if(a<0.0 || a>10.0){
			printf("nota invalida\n");
			continue;
		}else{
			for(;;){
				scanf("%f",&b);
				if(b<0.0 || b>10.0){
					printf("nota invalida\n");
					continue;
				}else
					break;
			}
			break;
		}
	}
	media=(a+b)/2;
	printf("media = %.2f\n",media);

	return 0;
}
