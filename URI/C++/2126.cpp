#include<iostream>
using namespace std;

int main(){
	string str1, str2;
	int qtd = 1;
	
	while(cin >> str1){
		cin >> str2;

		int total = 0;

		int pos = 0,aux;
		do{
			aux = str2.find(str1,pos);

			if(aux != string::npos){
				total++;
				pos = aux + 1;
			}else{
				break;
			}
		}while(true);
		
		cout << "Caso #" << qtd << ":" << endl;

		if(total == 0){
			cout << "Nao existe subsequencia" << endl;
		}else{
			cout << "Qtd.Subsequencias: " << total << endl;
			cout << "Pos: " << pos << endl;
		}

		cout << endl;

		qtd++;
	}

	return 0;
}