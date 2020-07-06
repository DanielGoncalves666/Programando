#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
	string str;

	while(getline(cin,str)){

		bool primeiro = true;
		char letra;
		int qtd = 0, aliteracoes = 0;
		for(int i=0; i<str.size(); i++){
			if(isupper(str[i])){
				str[i] = tolower(str[i]);
			}

			if(i == 0){
				letra = str[i];
				primeiro = false;
				qtd = 1;
			}else if(str[i] == ' '){
				primeiro = true;
			}else if(primeiro){
				if(str[i] == letra){
					qtd++;
					primeiro = false;
				}else{
					if(qtd >= 2)
						aliteracoes++;

					letra = str[i];
					primeiro = false;
					qtd = 1;
				}
			}else if(i == str.size() - 1){
				if(qtd >= 2)
					aliteracoes++;
			}
		}

		cout << aliteracoes << endl;
	}

	return 0;
}