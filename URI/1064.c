#include<stdio.h>
#include<stdlib.h>

	int i, h;
	float a,media;

int main(){
	for(i=0;i<6;i++){
		scanf("%f",&a);
		if(a>0){
			h++;
			media+=a;
		}
	}
	media=media/h;
	printf("%d valores positivos\n",h);
	printf("%.1f\n", media);
}
