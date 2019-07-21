#include<stdio.h>
#include<stdlib.h>

	int a,b,soma=0,i;

void main(){
	scanf("%d %d",&a,&b);
	
	if(a<=b){
		for(i=a;i<=b;i++){
			if(i%13!=0){
				soma+=i;
			}
		}
	}
	if(a>b){
		for(i=b;i<=a;i++){
			if(i%13!=0){
				soma+=i;
			}
		}
	}
	printf("%d\n",soma);

}
