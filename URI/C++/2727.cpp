#include<iostream>
using namespace std;

int main(){
	int N;
	string str;

	while(cin >> N){
		getline(cin,str);
		
		for(int i=0; i<N; i++){
			getline(cin,str);

			int pos = 0, qtd_espacos = 0;
			do{
				int aux = str.find(' ',pos);

				if(aux != string::npos){
					qtd_espacos++;
					pos = aux + 1;
				}else{
					break;
				}
			}while(true);

			int qtd_pontos = 0;
			for(int i=0;;i++){
				if(str[i] == ' ' || i == str.size()){
					break;
				}
				qtd_pontos++;
			}

			int total = qtd_espacos * 3 + qtd_pontos + 96;

			cout << (char) total << endl;
		}
	}

	return 0;
}