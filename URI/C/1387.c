#include<stdio.h>
#include<stdlib.h>

int L, R;

int main(){
	for(;;){
		scanf("%d %d",&L,&R);
		if(L+R == 0)
			break;
			
		printf("%d\n",L+R);
	}
	
	return 0;
}
