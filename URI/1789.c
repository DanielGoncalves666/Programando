#include<stdio.h>
#include<stdlib.h>

	int L,V,i,maior;

int main(){
	while(scanf("%d",&L)==1){
		for(i=0;i<L;i++){
			scanf("%d",&V);
			if(i==0)
				maior=V;
			if(maior<V)
				maior=V;
		}
		if(maior<10)
			printf("1\n");
		if(maior>=10 && maior<20)
			printf("2\n");
		if(maior>=20){
			printf("3\n");
		}
	}
	return 0;
}
