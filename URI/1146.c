#include<stdio.h>
#include<stdlib.h>

int X,i;

int main(){
	for(;;){
		scanf("%d",&X);
		if(X==0)
			break;
		for(i=1;i<=X;i++){
			if(i==X)
				printf("%d\n",i);
			else
				printf("%d ",i);
		}
	}	
	
	
	return 0;
}
