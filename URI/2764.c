#include<stdio.h>

int main(){
	int DD, MM, AA;

	scanf("%d/%d/%d",&DD,&MM,&AA);

	printf("%02d/%02d/%02d\n",MM,DD,AA);
	printf("%02d/%02d/%02d\n",AA,MM,DD);
	printf("%02d-%02d-%02d\n",DD,MM,AA);

	return 0;
}