#include<iostream>
using namespace std;

int main(){
	int N;

	while(cin >> N){
		int vet[N];
		for(int i=0; i<N; i++){
			cin >> vet[i];
		}

		int repeat;
		do{
			repeat = 0;
			for(int i=0; i<N-1; i++){
				if(vet[i] > vet[i + 1]){
					int aux = vet[i];
					vet[i] = vet[i + 1];
					vet[i + 1] = aux;
					repeat++;
				}
			}
		}while(repeat > 0);

		int total = 0;

		for(int i=0, h = N-1;;i++, h--){
			if(i == h || i > h)
				break;

			total += vet[h] - vet[i];
		}

		cout << total << endl;
	}

	return 0;
}