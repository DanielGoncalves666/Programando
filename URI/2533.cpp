#include<iostream>
using namespace std;

int main(){
	int M,N,C;

	while(cin >> M){
		int soma_nota_carga = 0, soma_carga = 0;
		for(int i=0; i<M; i++){
			cin >> N >> C;
			soma_nota_carga += N*C;
			soma_carga += C;
		}

		double result = soma_nota_carga/(soma_carga * 100.0);

		cout.precision(4);
		cout.setf(ios::fixed);
		cout << result << endl;
	}

	return 0;
}