#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	scanf("%d",&N);

	int At, Ae, Bt, Be, vida;
	for(int i=0; i<N; i++){
		scanf("%d %d %d %d", &At, &Ae, &Bt, &Be);
		scanf("%d",&vida);
		for(int h=0;;h++){
			if(h % Ae == 0){
				vida -= At;
				if(vida <= 0){
					printf("Andre\n");
					break;
				}
			}

			if(h % Be == 0){
				vida -= Bt;
				if(vida <= 0){
					printf("Beto\n");
					break;
				}
			}
		}
	}

	return 0;
}