#include<iostream>
using namespace std;

int main(){
	int N, M, num;

	cin >> N;
	cin >> M;

	int *vet = (int *) calloc(N,sizeof(int));
	for(int i=0; i<M; i++){
		cin >> num;

		vet[num-1] = 1;
	}

	int qtd = N;
	for(int i=0; i<N; i++){
		if(vet[i] == 1)
			qtd--;
	}

	cout << qtd << endl;

	return 0;
}