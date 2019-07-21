#include<stdio.h>
#include<stdlib.h>

	int N,i,a,b;
	float divi;

void main(){
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		if(a==0 && b==0 || b==0)
			printf("divisao impossivel\n");
		else{
			divi=(float)a/b;
			printf("%.1f\n",divi);
		}	
	}
}
