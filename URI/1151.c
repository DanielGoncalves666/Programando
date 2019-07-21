#include<stdio.h>
#include<stdlib.h>

int N,i,a=0,b=1,c;

int main(){
	scanf("%d",&N);
	if(N==1)
		printf("%d\n",a);
	else if(N>=2)
		printf("%d %d",a,b);
	if(N>2){
		for(i=0;i<N-2;i++){
			printf(" %d",a+b);
			c=a+b;
			a=b;
			b=c;
		}
	}
	printf("\n");
	
	return 0;
}
