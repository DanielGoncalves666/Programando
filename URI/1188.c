#include<stdio.h>
#include<stdlib.h>

	int i,h,k=5,j=6,a=0;
	double M[12][12],soma=0.0,media;
	char c;

void main(){
	scanf("%c",&c);
	for(i=0;i<12;i++){
		for(h=0;h<12;h++){
			scanf("%lf",&M[i][h]);
		}
	}
	for(i=0;i<12;i++){
		if(i<=5)
			continue;
		for(h=0;h<12;h++){
			if(h<=k || h>=j)
				continue;
			soma+=M[i][h];
			a++;
		}
		k--;
		j++;
	}
	if(c=='S'){
		printf("%.1lf\n",soma);
	}
	if(c=='M'){
		media=(float)soma/a;
		printf("%.1lf\n",media);
	}	
}
