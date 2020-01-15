#include<stdio.h>
#include<stdlib.h>

	int C,i,h,t,soma;

int main(){
	scanf("%d",&C);
	for(i=0;i<C;i++){
		soma=0;
		scanf("%d",&t);
		for(h=0;h<t;h++){
			if(h%2==0)
				soma+=1;
			if(h%2==1)
				soma+=-1;
		}
		printf("%d\n",soma);
	}
	return 0;
}
