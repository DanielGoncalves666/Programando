#include<iostream>
using namespace std;

int main(){
	int N;

	while(cin >> N){
		int qtd = (N+1) / 2, meio = (N - 1) / 2, aux = 0;
		char str[qtd+2][N];

		for(int i=0; i<qtd; i++){//as folhas da arvore
			for(int h=0; h<N; h++){
				str[i][h] = ' ';//preenche cada linha das folhas com espaços
			}

			for(int h=meio - aux; h<=meio+aux; h++){
				str[i][h] = '*';//coloca as folhas nos locais certos
			}
			aux++;
		}

		aux = 0;
		for(int i=qtd; i<qtd+2; i++){//o tronco da arvore
			for(int h=0; h<N; h++){
				str[i][h] = ' ';//preenche cada linha das folhas com espaços
			}

			for(int h=meio - aux; h<=meio+aux; h++){
				str[i][h] = '*';//coloca as folhas nos locais certos
			}
			aux++;
		}

		for(int i=0; i<qtd+2; i++){
			for(int h=0; h<N; h++){
				if(h > meio){//gambiarra
					if(str[i][h] == ' ' && str[i][h-1] == '*')
						break;
				}

				cout << str[i][h];
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}