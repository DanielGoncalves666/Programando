#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string chave, str,str_aux;
	int letra = (int) 'a';

	cin >> chave;
	cin >> str;

	str_aux = str;

	for(int i=0; i<26; i++, letra++){
		for(int h=0; h<str.size(); h++){
			if(str[h] == (char) letra)
				str_aux[h] = chave[i];
		}
	}

	cout << str_aux << endl;

	return 0;
}