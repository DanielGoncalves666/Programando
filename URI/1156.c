#include<stdio.h>
#include<stdlib.h>

	float s=1.0,a=3.0,b=2.0;

void main(){
	for(;a<=39;){
		s=(float)s+a/b;
		a+=2;
		b*=2;
	}
	printf("%.2f\n",s);
}
