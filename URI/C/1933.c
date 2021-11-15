#include<stdio.h>
#include<stdlib.h>

int a,b;

int main(){
	scanf("%d %d",&a,&b);

	if(a == b)
		printf("%d\n",a);
	else if(a > b)
		printf("%d\n",a);
	else if(a < b)
		printf("%d\n",b);

	return 0;
}
