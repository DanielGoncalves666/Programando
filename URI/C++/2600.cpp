#include<iostream>
using namespace std;

int main(){
	int N, S, I, vet[4];

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> S;
		cin >> vet[0] >> vet[1] >> vet[2] >> vet[3];
		cin >> I;

		int verify[6] = {S, I, vet[0], vet[1], vet[2], vet[3]};
		bool erro = false;

		for(int h=0; h<5;){
			if(verify[h] > verify[h+1]){
				int aux = verify[h];
				verify[h] = verify[h+1];
				verify[h+1] = aux;
				h = 0;
			}else
				h++;
		}

		for(int h=0; h<5; h++){
			if(verify[h] == verify[h+1] || verify[h] == 0 || verify[h] >= 7 || verify[6] >= 7){
				erro = true;
				break;
			}
		}

		if(erro){
			cout << "NAO" << endl;
		}else if(S + I == 7 && vet[0] + vet[2] == 7 && vet[1] + vet[3] == 7)
			cout << "SIM" << endl;
		else 
			cout << "NAO" << endl;
	}

	return 0;
}