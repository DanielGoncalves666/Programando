#include<iostream>
using namespace std;

int main(){
	int N, qtd = 0,ciclo;

	while(1){
		cin >> N;

		if(N == -1)
			break;

		qtd++;
		ciclo = N/2;

		cout << "Experiment " << qtd << ": " << ciclo << " full cycle(s)" << endl;
	}

	return 0;
}