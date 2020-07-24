#include<iostream>
using namespace std;

int main(){
	int N;

	cin >> N;
	int vet[N];

	if(N == 1)
		cout << "1" << endl;
	else{
		vet[0] = 1;
		vet[1] = 1;

		for(int i=2; i<N; i++){
			vet[i] = vet[i-2] +  vet[i-1];
		}

		for(int i=N-1; i>=0; i--){
			if(i != N-1){
				cout << " ";
			}

			cout << vet[i];
		}
		cout << endl;
	}

	return 0;
}