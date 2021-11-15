//terminar
#include<iostream>
using namespace std;

int main(){
	int N;

	cin >> N;
	int vet[N];

	for(int i=0; i<N; i++){
		cin >> vet[N];
	}

	int qtd = 0,diferenca, diferenca_anterior, num_qtd = 0;
	if(N == 1){
		cout << "1" << endl;
	}else{
		for(int i=0; i<N-1; i++){

			diferenca = vet[i+1] - vet[i];

			if(i == 0){
				diferenca_anterior = diferenca;
				num_qtd++;
				continue;
			}

			if(diferenca != diferenca_anterior){
				qtd++;
			}
			
			num_qtd++;
			diferenca_anterior = diferenca;

		}
	}

	return 0;
}