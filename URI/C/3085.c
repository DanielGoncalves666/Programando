#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double dist_euclidiana(int origem1, int origem2, int xF, int yF);

int main(){
	int n, k, xf, yf;
	char letra;
	int origem_x = 0, origem_y = 0;

	scanf("%d %d %d %d",&n,&k,&xf,&yf);

	int trap = 0;
	for(int i=0; i<n; i++){
		scanf(" %c",&letra);

		if(k < dist_euclidiana(origem_x,origem_y,xf,yf)){
			if(i == 0)
				trap = 1;
			else if(trap == 0)
				trap = i;
		}else{
			if(letra == 'D')
				origem_x++;
			else if(letra == 'E')
				origem_x--;
			else if(letra == 'C')
				origem_y++;
			else if(letra == 'B')
				origem_y--;
		}
	}

	if(trap > 0)
		printf("Trap %d\n",trap);
	else if(origem_x != xf || origem_y != yf)
		printf("Trap %d\n",n);
	else
		printf("Sucesso\n");
	

	return 0;
}

double dist_euclidiana(int origem1, int origem2, int xF, int yF){
	double dist = sqrt(pow(xF - origem1,2) + pow(yF - origem2,2));
	return dist;
}