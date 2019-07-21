#include<stdio.h>
#include<stdlib.h>

	int i,p=0;
	float a;

void main(){
	for(i=0;i<6;i++){
		scanf("%f",&a);
		if(a>0)
			p++;
	}
	printf("%d valores positivos\n",p);
}
