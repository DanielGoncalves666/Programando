#include<stdio.h>

int main(){
	int hora, minutos;

	while(scanf("%d:%d",&hora,&minutos) != EOF){

		hora++;//atraso maximo de uma hora

		if(hora < 8){
			printf("Atraso maximo: 0\n");
		}else if(hora == 8){
			printf("Atraso maximo: %d\n",minutos);
		}else if(hora > 8){
			printf("Atraso maximo: %d\n",60 * (hora - 8) + minutos);
		}
	}

	return 0;
}