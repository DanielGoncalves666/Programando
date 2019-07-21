#include<stdio.h>
#include<stdlib.h>

	int a,b,i,soma=0;

int main(){
	scanf("%d %d",&a,&b);
	if(a<=b){
		for(i=a+1;i<b;){
			if(i%2==0)
				i++;	
			else{
				soma+=i;
				i+=2;
			}
		}
	}else{
		for(i=b+1;i<a;){
			if(i%2==0)
				i++;	
			else{
				soma+=i;
				i+=2;
			}
		}
	}
	printf("%d\n",soma);

	return 0;
}
