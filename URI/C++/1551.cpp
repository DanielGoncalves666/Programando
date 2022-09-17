#include<iostream>
using namespace std;

int main(){
	int N,qtd;
	string frase;

	cin >> N;
	getline(cin,frase);//buffer
	for(int i=0; i<N; i++){
		getline(cin,frase);

		qtd = 0;
		size_t pos;
		for(int letra = 'a'; letra <= 'z'; letra++){
			pos = frase.find((char) letra);

			if(pos != string::npos)
				qtd++;
		}

		if(qtd == 26)
			cout << "frase completa\n";
		else if(qtd >= 13)
			cout << "frase quase completa\n";
		else
			cout << "frase mal elaborada\n";
	}

	return 0;
}