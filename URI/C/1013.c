#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	int a,b,c,m1,m2;

void main(){
	scanf("%d %d %d",&a,&b,&c);
	m1=(a+b+abs(a-b))/2;
	m2=(m1+c+abs(m1-c))/2;
	printf("%d eh o maior\n",m2);
}
