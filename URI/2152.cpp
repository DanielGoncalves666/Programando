#include<stdio.h>

int main(){
	int N,h,m,p;

	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d",&h,&m,&p);

		printf("%02d:%02d - A porta ",h,m);
		if(p == 1)
			printf("abriu!\n");
		else
			printf("fechou!\n");
	}
	return 0;
}