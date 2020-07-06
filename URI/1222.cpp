#include<iostream>
#include<string>
using namespace std;

int main(){
	int N, L, C;
	string str;

	while(cin >> N >> L >> C){
		int qtdLinhas = 0, linha = 0;
		for(int i=0; i<N; i++){
			cin >> str;

			int total = linha + str.size() + 1;
			
			if(linha == 0){
				linha += str.size();
				qtdLinhas++;
			}else if(total < C)
				linha = total;
			else if(total == C)
				linha = 0;
			else if(total > C){
				linha = str.size();
				qtdLinhas++;
			}
			
		}
		int paginas = qtdLinhas / L;

		if(qtdLinhas % L != 0)
			paginas++;

		cout << paginas << endl;
	}

	return 0;
}