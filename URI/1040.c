#include<stdio.h>
#include<stdlib.h>

	float N1, N2, N3, N4, media, exam;

void main(){
	scanf("%f %f %f %f",&N1,&N2,&N3,&N4);
	media=(N1*2+N2*3+N3*4+N4*1)/10;
	printf("Media: %.1f\n", media);
	if(media>7.0)
		printf("Aluno aprovado.\n");
	if(media<5.0)
		printf("Aluno reprovado.\n");
	if(media>=5.0 && media<=6.9){
		printf("Aluno em exame.\n");
		scanf("%f",&exam);
		printf("Nota do exame: %.1f\n", exam);
		media=(media+exam)/2;
		
		if(media>=5.0)
			printf("Aluno aprovado.\nMedia final: %.1f\n",media);
		else
			printf("Aluno reprovado.\nMedia final: %.1f\n",media);
	}
	
	
}
