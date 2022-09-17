//imcompleto

#include<stdio.h>
#include<stdlib.h>

int E,I,V,i,h;

void causa(int **mat, int *eventos, int E, int i){
	for(h=0; h<E; h++){
		if(eventos[mat[i][0]] != 1)
			continue;
			
		eventos[mat[i][1]] = 1;
		if(mat[i][1] < i)//caso já se tenha verificado este evento anteriormente
			causa(mat,eventos,E,mat[i][1]);
	}
}

void consequencia(int **mat, int *eventos, int I, int E, int h){
	int qtd = 0, num;
	for(i=0; i<I; i++){
		if(eventos[mat[i][1]] != 1)
			continue;
			
		qtd++;
		num = i;
		if(mat[i][0] == 0)
			eventos[mat[i][0]] = 10;						
	}
	if(qtd == 1){
		eventos[mat[num][0]] = 1;
		causa(mat,eventos,E,mat[num][0]);
	
	}else{
		for(int j=0; j<E; j++){
			if(eventos[mat[num][0]] == 10)
				eventos[mat[num][0]] = 2;
		}
	}	
}

int main(){
	scanf("%d %d %d",&E,&I,&V);	
	int certo[V];
	
	int *eventos = calloc(sizeof(int),E);
	int **mat = malloc(sizeof(int *)*I);
	for(i=0; i<I; i++)
		mat[i] = malloc(sizeof(int)*2);

	for(i=0; i<I; i++){
		scanf("%d %d",&mat[i][0],&mat[i][1]);
	}

	for(i=0; i<V; i++){
		scanf("%d",&certo[i]);
		eventos[certo[i]] = 1;
	}
	
	for(i=0; i<I; i++)
		causa(mat,eventos,E,i);
	
	for(h=0; h<V; h++){
		consequencia(mat,eventos,I,V,h);
	}
	
	for(i=0; i<E; i++){
		if(eventos[i] == 1)
			printf("%d ",i+1);
	}


	return 0;
}
