#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	int vet[N+1][N+1], aux[N][N];
	for(int i=0; i<N+1; i++){
		for(int h=0; h<N+1; h++){
			cin >> vet[i][h];
		}
	}

	for(int i=0; i<N; i++){
		for(int h=0; h<N; h++){
			aux[i][h] = vet[i][h] + vet[i+1][h] + vet[i][h+1] + vet[i+1][h+1];

			if(aux[i][h] >= 2)
				cout << "S";
			else
				cout << "U";
		}
		cout << endl;
	}

	return 0;
}
