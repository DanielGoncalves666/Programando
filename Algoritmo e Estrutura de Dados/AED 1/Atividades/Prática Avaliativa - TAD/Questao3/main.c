#include <stdio.h>
#include "../include/esfera.h"
#include "../include/ponto.h"

int main()
{
	int x = 0, y = 0, z = 0;
	int x1 = 0, y1= 0, z1 = 0;
	Esfera *bola = NULL;
	double raio = 0;
	double area = 0;
	double volume = 0;

	while(1)
	{
		printf("Entre com as coordenadas x,y e z do ponto que representa o centro da esfera:\n");
		scanf("%d %d %d",&x,&y,&z);
		printf("\nEntre com as coordenadas x,y e z do ponto que representa a superfície da esfera:\n");
		scanf("%d %d %d",&x1, &y1, &z1);

		bola = criar_esfera(x,y,z,x1,y1,z1);

		if(bola == NULL){
			printf("\nFalha! -- Entre com os dados novamente!\n");
			continue;
		}

		break;
	}

	raio = raio_esfera(bola);
	area = area_esfera(raio);
	volume = volume_esfera(raio);

	printf("\n---A esfera passada possui:---\nraio = %.2lf\narea = %.2lf\nvolume = %.2f\n",raio,area,volume);

	libera_esfera(&bola);

	return 0;
}