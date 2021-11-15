#include<iostream>
using namespace std;

int main(){
	int N,saldo,num;
	
	cin >> N >> saldo;

	int menor = saldo;
	for(int i=0; i<N; i++){
		cin >> num;
		saldo += num;

		if(saldo < menor)
			menor = saldo;
	}

	cout << menor << endl;

	return 0;
}