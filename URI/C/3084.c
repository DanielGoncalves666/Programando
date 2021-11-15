#include<stdio.h>

int main(){
	int hora, minuto;

	while(scanf("%d %d",&hora,&minuto) != EOF){
		int h = hora / 30;
		int m = (minuto / 30) * 5 + ((minuto % 30)/6);

		printf("%02d:%02d\n",h,m);
	}
	return 0;
}