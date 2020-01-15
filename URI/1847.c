#include<stdio.h>
#include<stdlib.h>

	int a,b,c;

int main(){
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		if(b<=c)
			printf(":)\n");
		if(b>c){
			if(abs(a-b)>abs(b-c))
				printf(":)\n");
			if(abs(a-b)<=abs(b-c))
				printf(":(\n");
		}
	}
	if(a<b){
		if(b>=c)
			printf(":(\n");
		if(b<c){
			if(abs(a-b)>abs(b-c))
				printf(":(\n");
			if(abs(a-b)<=abs(b-c))
				printf(":)\n");
		}
	}
	if(a==b){
		if(b<c)
			printf(":)\n");
		if(b>=c)
			printf(":(\n");
	}
	
	return 0;
}
