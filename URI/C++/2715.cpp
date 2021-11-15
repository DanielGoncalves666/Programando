//qualquer subsequencia de trabalhos pode ser pega, n apenas dividir entre o começo pra um e o fnal pro outro
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int N;

	while(cin >> N){
		int vet[N];
		unsigned long long soma = 0;
		for(int i=0; i<N; i++){
			cin >> vet[i];
			soma += vet[i];
		}

		if(N == 1){
			cout << vet[0] << endl;
			continue;
		}

		int menor = 0;
		unsigned long long acumulativo = 0, aux;
		for(int i=0; i<N; i++){
			acumulativo += vet[i];
			soma -= vet[i];
			aux = max(acumulativo,soma) - min(acumulativo,soma);

			if(i == 0){
				menor = aux;
				continue;
			}else if(menor > aux){
				menor = aux;
			}else{
				break;
			}
		}

		cout << menor << endl;
	}

	return 0;
}