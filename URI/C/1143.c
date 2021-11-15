#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	int a,i;

void main(){
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		printf("%d ",i);
		printf("%.0f ",pow(i,2));
		printf("%.0f\n",pow(i,3));
	}
}
