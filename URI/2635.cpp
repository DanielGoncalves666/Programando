#include<iostream>
using namespace std;

int main(){
	int N,Q;

	while(cin >> N){
		string str[N], consulta;
		int tamanho[N];

		for(int i=0; i<N; i++){
			cin >> str[i];
			tamanho[i] = str[i].size();
		}

		cin >> Q;
		for(int i=0; i<Q; i++){
			cin >> consulta;

			int qtd = 0, pos, maior = 0;
			for(int h=0; h<N; h++){
				pos = str[h].find(consulta,0);

				if(pos == 0){//se a consulta começar no inicio da palavra armazenada;
					qtd++;

					if(maior < tamanho[h]){
						maior = tamanho[h];
					}
				}
			}

			if(qtd == 0){
				cout << "-1" << endl;
			}else
				cout << qtd << " " << maior << endl;
		}
	}

	return 0;
}