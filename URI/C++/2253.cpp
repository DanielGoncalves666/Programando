#include<iostream>
#include<cctype>
using namespace std;

int main(){
	string str;
	bool ok;

	while(getline(cin,str)){
		if(str.size() < 6 || str.size() > 32){//tamanho n permitido
			cout << "Senha invalida." << endl;
			continue;
		}

		ok = false;
		for(int i=0; i<str.size(); i++){
			if(isalnum(str[i]) == 0){
				cout << "Senha invalida." << endl;
				ok = true;
				break;
			}
		}

		if(ok)
			continue;

		if(str.find_first_of("0123456789") == string::npos){//nao possui numeros
			cout << "Senha invalida." << endl;
			continue;
		}

		if(str.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos){//nao possui letra minuscula
			cout << "Senha invalida." << endl;
			continue;
		}

		if(str.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos){//nao possui letra maiuscula
			cout << "Senha invalida." << endl;
			continue;
		}

		cout << "Senha valida." << endl;
	}


	return 0;
}