#include<stdio.h>
#include<stdlib.h>

int M, A, B, C;

int main(){
	scanf("%d %d %d",&M,&A,&B);
	
	C = M - (A + B);
	
	if(A > B && A >= C)
		printf("%d",A);
	else if(B > A && B >= C)
		printf("%d",B);
	else if(C > A && C >= B)
		printf("%d",C);
	
	return 0;
}
