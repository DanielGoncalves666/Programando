#include<stdio.h>
#include<stdlib.h>

int T, PA, PB;
double G1, G2;

int main(){
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d %d %lf %lf",&PA,&PB,&G1,&G2);
		for(int h=1; ;h++){
			PA +=  (PA * (G1/100.0));
			PB +=  (PB * (G2/100.0));
			
			if(h >= 101){
				printf("Mais de 1 seculo.\n");
				break;
			}
			
			if(PA > PB){
				printf("%d anos.\n",h);
				break;
			}	
		}
	}

	return 0;
}
