#include<iostream>
#include<cmath>
using namespace std;

int main(){
	string str[4], mensagem;
	int F = 0,L = 0,aux;

	for(int i=0; i<4; i++){
		cin >> str[i];
	}

	int last = str[0].size() - 1;
	for(int i=0, p = 3; i<4; i++, p--){
		F += (str[i][0] - '0') * pow(10,p);
		L += (str[i][last] - '0') * pow(10,p);
	}

	for(int i=1; i<last; i++){
		aux = (str[0][i] - '0') * 1000 + (str[1][i] - '0') * 100 + (str[2][i] - '0') * 10 + (str[3][i] - '0');
		aux = F * aux + L;
		aux %= 257;
		
		mensagem.append(1,(char) aux);
	}

	cout << mensagem << endl;

	return 0;
}