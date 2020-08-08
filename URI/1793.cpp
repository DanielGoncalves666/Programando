#include<iostream>
using namespace std;

int main(){
	int N;

	while(true){
		cin >> N;

		if(N == 0)
			break;

		int vet[N];
		for(int i=0; i<N; i++){
			cin >> vet[i];
		}

		int total = 0;

		for(int i=0; i<N; i++){
			if(i == N - 1){
				total += 10;
			}else if(vet[i] + 10 <= vet[i+1]){
				total += 10;
			}else{
				total += vet[i+1] - vet[i];
			}
		}

		cout << total << endl;
	}

	return 0;
}