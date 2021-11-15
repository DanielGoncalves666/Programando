#include<stdio.h>
#include<stdlib.h>

double a,b, aumento;

int main(){
	scanf("%lf %lf",&a,&b);
	aumento = (100*b)/a;
	aumento -= 100.00;
	
	printf("%.2f%%\n",aumento);
	
	return 0;
}
