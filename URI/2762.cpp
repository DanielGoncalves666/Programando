#include<iostream>
using namespace std;

int main(){
	string str;

	cin >> str;

	int pos = str.find('.');

	bool zero_esquerda = true;
	for(int i = pos + 1; i<str.size(); i++){
		if(str[i] == '0' && zero_esquerda){
			if(i == str.size() - 1)//se for a ultima posicao
				cout << "0";

			continue;
		}else{
			zero_esquerda = false;
		}

		cout << str[i];
	}

	cout << ".";

	for(int i=0; i<pos; i++){
		cout << str[i];
	}

	cout << endl;

	return 0;
}