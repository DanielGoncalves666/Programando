#include<stdio.h>
#include<math.h>

int main(){
	int N,x,y;

	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d",&x,&y);

		printf("%.0f cm2\n",floor((x*y)/2.0));
	}

	return 0;
}