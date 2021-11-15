#include<iostream>
#include<string>
using namespace std;

bool determinaCase(char caracter);

int main(){
	string str;

	while(getline(cin,str)){	
		int anterior = -1;//-1 -- > nada ainda; 1 --> maisculo; 0 --> minusculo

		for(int i=0; i<str.size(); i++){
			if(str[i] == ' '){
				continue;
			}else if(anterior == -1 || anterior == 0){			
				bool Case = determinaCase(str[i]);
			
				if(!Case){
					str[i] = (int) str[i] - 32;
				}

				anterior = 1;
			}else if(anterior == 1){
				bool Case = determinaCase(str[i]);

				if(Case){
					str[i] = (int) str[i] + 32;
				}
				
				anterior = 0;
			}
		}

		cout << str << endl;
	}

	return 0;
}

bool determinaCase(char caracter){
	if(caracter >= 65 && caracter <= 90)
		return true;
	else if(caracter >= 97 && caracter <=122)
		return false;
}