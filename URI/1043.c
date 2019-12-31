#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float A, B, C;

void area_trapezio(){
	float area = ((A + B) * C) / 2; 
	printf("Area = %.1f\n", area);
}

void perimetro_triangulo(){
	float perimetro = A + B + C;
	printf("Perimetro = %.1f\n", perimetro);
}

void verifica_triangulo(){//função que verifica se três valores formam um triângulo
	if((A < B + C) && (B < A + C) && (C < A + B)){
		if((fabs(B - C) < A) && (fabs(A - C) < B) && (fabs(A - B) < C))
			perimetro_triangulo();
		else
			area_trapezio();
	}else
		area_trapezio();
}

int main(){
	scanf("%f %f %f",&A,&B,&C);
	verifica_triangulo();

	return 0;
}
