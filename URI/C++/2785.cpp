//desconsiderei que precisava da caixa de baixo, senao tava certo
#include<iostream>
using namespace std;

int main(){
	int N;

	cin >> N;

	int vet[N][N];
	for(int i=0; i<N; i++){
		for(int h=0; h<N; h++){
			cin >> vet[i][h];
		}
	}

	for(int i=0; i<N; i++){
		for(int h=0; h<N-1;){
			if(vet[i][h] > vet[i][h+1]){
				int aux = vet[i][h];
				vet[i][h] = vet[i][h+1];
				vet[i][h+1] = aux;
				h = 0;
			}else
				h++;
		}
	}

	int total = 0;
	for(int i=0; i<N; i++){
		for(int h=0;h<=i;h++){
			total += vet[i][h];
		}
	}

	cout << total << endl;

	return 0;
}