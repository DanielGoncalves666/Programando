#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int N, num;
	char letra;

	while(cin >> N){
		int *numeros = NULL, *qtd = NULL;
		char *lado = NULL;
		int qtd_validos = 0;
		for(int i=0; i<N; i++){
			cin >> num >> letra;
			
			if(i == 0){
				qtd_validos++;
				numeros = (int *) realloc(numeros,qtd_validos*sizeof(int));
				lado = (char *) realloc(lado,qtd_validos*sizeof(char));
				qtd = (int *) realloc(qtd,qtd_validos*sizeof(int));
				
				numeros[0] = num;
				qtd[0] = 1;
				lado[0] = letra;
			}else{
				for(int h=0;; h++){
					if(num == numeros[h] && letra == lado[h]){
						qtd[h]++;
						break;
					}

					if(h + 1 == qtd_validos){
						qtd_validos++;
						h++;
						numeros = (int *) realloc(numeros,qtd_validos*sizeof(int));
						lado = (char *) realloc(lado,qtd_validos*sizeof(char));
						qtd = (int *) realloc(qtd,qtd_validos*sizeof(int));

						numeros[h] = num;
						qtd[h] = 1;
						lado[h] = letra;

						break; //senao entramos em um lopp
					}
				}
			}
		}

		for(int i=0; i<qtd_validos-1;){
			if(numeros[i] > numeros[i+1]){
				int aux = numeros[i];
				numeros[i] = numeros[i+1];
				numeros[i+1] = aux;
				aux = qtd[i];
				qtd[i] = qtd[i+1];
				qtd[i+1] = aux;
				i = 0;
			}else
				i++;
		}

		int total = 0;
		for(int i=0; i<qtd_validos-1;){
			if(numeros[i] == numeros[i+1]){
				if(qtd[i] >= qtd[i+1])
					total += qtd[i+1];
				else
					total += qtd[i];
				
				i += 2;
			}else{
				i++;
			}
		}

		cout << total << endl;
	}

	return 0;
}