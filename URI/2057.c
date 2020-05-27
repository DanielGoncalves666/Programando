#include<stdio.h>
#include<stdlib.h>

int S, T, F, time;

int main(){
	scanf("%d %d %d",&S,&T,&F);
	time = S + T + F;
	if(time >= 24)
		time -= 24;
	else if(time < 0)
		time += 24;
		
	printf("%d\n",time);

	return 0;
}
