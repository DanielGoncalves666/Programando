#include<stdio.h>
#include<stdlib.h>

int N,m1,m2;

int main(){

	scanf("%d",&N);
	int vet[N],qtd[N];
	
	for(int i=0; i<N; i++){
		scanf("%d",&vet[i]);
		qtd[i] = 0;
	}

	for(int i=0; i<N; i++){
		qtd[vet[i]-1]++;//aumenta a qtd de cada número que for encontrado
	}
	
	for(int i=0; i<N; i++){
		if(qtd[vet[i]-1] > 0){//se a qtd daquilo número for maior que zero
			for(int h=0; h<N;){
				if(i==h){//caso a verificação for no msm número, ignoramos
					h++;
					continue;
				}
				if(vet[h] == vet[i] && vet[h+1] == vet[i]){//caso a posição h tiver o msm número da posição h+1, retiramos 2 da contagem
					qtd[vet[i]-1] -= 2;
					h+=2;//incrementamos h em 2 posições
					while(vet[h] == vet[i]){//fará a comparação e diminuirá um da contagem enquanto se verificar igualdade
						qtd[vet[i]-1]--;
						h++;
					}
				}else
					h++;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(i == 0){//se for a primeira posição do vetor
			m1 = qtd[i];// m1 recebe a quantidade do primeiro elemento do vetor, ou seja, a quantidade de 0 que podem ser marcadas
			m2 = 0;//zeramos m2
		}else if(i == 1){//se for a segunda posição do vetor
			m2 = qtd[i];//atribuimos o seu valor para m2
			if(m1 < m2){//verificamos se m2 é maior que m1, caso for, invertemos os valores
				int aux = m1;
				m1 = m2;
				m2 = aux;
			}
		}else{
			if(qtd[i] > m2){//caso a quantidade na poisção i por maior que o valor armazenado em m2
				m2 = qtd[i];//caso for, substituimos o valor em m2
				if(m1 < m2){//fazemos a verificação de o valor de m2 é maior que m1
					int aux = m1;
					m1 = m2;
					m2 = aux;//se for, invertemos os valores
				}		
			}
		}
	}
	
	printf("%d",m1+m2);

	return 0;
}
