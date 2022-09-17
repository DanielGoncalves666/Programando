#include<stdio.h>
#include<stdlib.h>

int A,B,q=0,r=0;

int main(){
	scanf("%d %d",&A,&B);
	
	if(A >= 0){
		q = A/B;
		r = A%B;
	}else{
		if(A%B == 0){
			q = A/B;
			r = 0;
		}else{
			if(B >= 0){	
				q = A/B - 1;
				r = (q*B - A) * -1;
			}else{
				q = A/B + 1;
				r = (q*B - A) * -1;
			}
		}
	}
	
	printf("%d %d\n",q,r);

	return 0;
}
