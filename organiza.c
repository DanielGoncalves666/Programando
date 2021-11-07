#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int qtd, tamanho, a, b;

void organiza_vetor(float *vet, int tamanho);//função que organiza em ordem crescente um vetor com tamanho 'tamanho'
void troca(float *i, float *h);//função responsavel por trocar os valores entre duas variaveis ou posições de um vetor
void imprimeVetorOrganizado(float *vet, int tamanho);//função para imprimir o vetor organizado
float calculaMedia(float *vet, int tamanho);//função que calcula a média dos valores de um vetor
float calculaDesvioAbsoluto(float media, float valor);//função que retorna o desvio absoluto de um valor em um conjunto de numeros
float calculaDesvioPadrao(float *vet, int tamanho);//calcula o desvio padrao do conjunto

int main(){
	scanf("%d %d",&qtd,&tamanho);//quantidade de vetores a serem organizados e o tamanho deles
	
	float vetor[tamanho], desvioPadrao;
	
	for(int i=0; i<qtd; i++){
		for(int h=0; h<tamanho; h++){
			scanf("%f",&vetor[h]);//armazena os valores no vetor
		}
		organiza_vetor(vetor,tamanho);
		//scanf("%d %d ",&a,&b);//localização da porta
		
		desvioPadrao = calculaDesvioPadrao(vetor,tamanho);
		
		printf("Desvio Padrão = %f", desvioPadrao);
		//printf("\t%d %d\n\n",a,b);
	}
	return 0;
}

void organiza_vetor(float *vet, int tamanho){//função que organiza em ordem crescente um vetor com tamanho 'tamanho'

	//para organizar esse vetor em ordem crescente, verificações serão feitas se comparando determinada posição com sua posterior, devido a esse fato, a ultima não sofrera o processo, pois caso contrario uma falha de segmentação acontecerá
	int fim;
	do{
		fim = 0;//atribuimos zero para a variavel, caso todo o vetor esteja organizado, ela n recebe 1, o que indica o fim do laço
		for(int n=0; n<tamanho-1; n++){//ajudara a percorrer o vetor, da primeira posição até a penultima
			if(vet[n] > vet[n+1]){//caso a posição em analise for maior que a proxima
				troca(&vet[n],&vet[n+1]);//troca os valores de posição
				fim = 1;//muda pra 1 indicando que pelo menos uma operação de reorganização foi realizada e pra ter certeza que está tudo nos conformes, é necessário mais uma repetição, pelo menos
			}
		}
	}while(fim == 1);//vai parar quando nenhuma operação tiver sido realizado no vetor nesses ciclo
}

void troca(float *i, float *h){//função responsavel por trocar os valores entre duas variaveis ou posições de um vetor
	float aux;
	aux = *i;//aux recebe o valor de *i
	*i = *h;//*i recebe o valor de *h
	*h = aux;//*h recebe o valor de *i
}



// - - - - Novas Funções - - - - //


void imprimeVetorOrganizado(float *vet, int tamanho){//função para imprimir o vetor organizado
	for(int h=0; h<tamanho; h++){
		printf("%.0f ",vet[h]);//imprime o vetor organizado
	}
}


float calculaMedia(float *vet, int tamanho){//função que calcula a média dos valores de um vetor
	float soma=0.0;
	for(int i=0; i<tamanho; i++){
		soma += vet[i];
	}
	
	return soma/tamanho;	
}


float calculaDesvioAbsoluto(float media, float valor){//função que retorna o desvio absoluto de um valor em um conjunto de numeros
	return abs(valor-media);
}


float calculaDesvioPadrao(float *vet, int tamanho){//calcula o desvio padrao do conjunto
	float desvioAbsoluto, variancia = 0.0;
	
	float media = calculaMedia(vet,tamanho);
	
	for(int i=0; i<tamanho; i++){
		desvioAbsoluto = calculaDesvioAbsoluto(media,vet[i]);//retorna o desvio absoluto de cada valor do vetor
		variancia += pow(desvioAbsoluto,2);//eleva cada desvio absoluto ao quadrado e então soma na variavel variancia
	}
	variancia /= tamanho;//de modo a obter a variancia do conjunto, dividimos a soma obtida pela quantidade de elementos
	
	printf("Variância = %f\t",variancia);
	return sqrt(variancia);//retorna o desvio padrao (raiz quadrada da variancia)
}





