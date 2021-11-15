#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long a,i,b,c;

int main(){
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		b=pow(i,2);
		c=pow(i,3);
		printf("%d %d %d\n",i,b,c);
		printf("%d %d %d\n",i,b+1,c+1);
	}
	return 0;
}
