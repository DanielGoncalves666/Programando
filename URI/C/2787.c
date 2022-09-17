#include<stdio.h>
#include<stdlib.h>

int L,C;

int main(){
	scanf("%d %d",&L,&C);
	
	if(L%2 == 0 && C%2 == 0)
		printf("1\n");
	else if(L%2 == 0 && C%2 == 1)
		printf("0\n");	
	else if(L%2 == 1 && C%2 == 0)
		printf("0\n");		
	else if(L%2 == 1 && C%2 == 1)
		printf("1\n");	

	return 0;
}
