#include<stdio.h>
#include<stdlib.h>

int A,B,q,r;

int main(){
	scanf("%d %d",&A,&B);
	r = abs(A%B);
	q = (A - r)/B;
	
	printf("%d %d\n",q,r);

	return 0;
}
