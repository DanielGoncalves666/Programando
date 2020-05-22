#include<stdio.h>
#include<stdlib.h>

int M, F1, F2, F3;

int main(){
	scanf("%d %d %d",&M,&F1,&F2);
	
	F3 = M - F1 - F2;
	
	if(F3>F2 && F3>F1)
		printf("%d\n",F3);
	else if(F2>F1 && F2>F3)
		printf("%d\n",F2);
	else 
		printf("%d\n",F1);

	return 0;
}
