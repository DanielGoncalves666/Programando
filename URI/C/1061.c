#include<stdio.h>
#include<stdlib.h>

int dia1, hora1, min1, seg1;
int dia2, hora2, min2, seg2;
int dias=0, horas=0, minutos=0, segundos=0;
char vet1[4], vet[2];

void entrada(){
	scanf("%s %d",vet1,&dia1);
	scanf("%d %s %d %s %d",&hora1,vet,&min1,vet,&seg1);
	scanf("%s %d",vet1,&dia2);
	scanf("%d %s %d %s %d",&hora2,vet,&min2,vet,&seg2);
}

void somarTudo(){
	if(dia1 != dia2)
		dias = dia2 - (dia1 + 1);
	if(dia1 != dia2 || hora1 != hora2){
		if(dia1 == dia2)
			horas = hora2 - (hora1 + 1);
		else
			horas = hora2 + (24 - (hora1 + 1));
	}
	if(dia1 != dia2 || hora1 != hora2 || min1 != min2){
		if(dia1 == dia2 && hora1 == hora2)
			minutos = min2 - (min1 + 1);
		else
			minutos = min2 + (60 - (min1 + 1));
	}
	segundos = seg2 + (60 - seg1);
}

void conversao(){
	if(segundos >= 60){
		minutos++;
		segundos -= 60;
	}
	if(minutos >= 60){
		horas++;
		minutos -= 60;
	}
	if(horas >= 24){
		dias++;
		horas -= 24;
	}
}

void imprimir(){
	printf("%d dia(s)\n", dias);
	printf("%d hora(s)\n", horas);
	printf("%d minuto(s)\n", minutos);
	printf("%d segundo(s)\n", segundos);
}

int main(){
	entrada();
	somarTudo();
	conversao();
	imprimir();

	return 0;
}
