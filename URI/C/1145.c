#include<stdio.h>
#include<stdlib.h>

int X,Y,i;

int main(){
	scanf("%d %d",&X,&Y);
	
	for(i=1;i<=Y;i++){
		if(i%X==0)
			printf("%d\n",i);
		else
			printf("%d ",i);
		
	}
	if((i-1)%X!=0){
		printf("\n");
	}
	return 0;
}
