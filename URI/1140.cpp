#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool tautograma(int tamanho, string str, char letra);

int main(){
	string str;
	int tamanho;
	char letra;
	
	for(;;){
		getline(cin, str);
		if(str[0] == '*')
			break;
			
		tamanho = str.size();
		bool boolean = tautograma(tamanho, str, letra);
		
		if(boolean)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}

bool tautograma(int tamanho, string str, char letra){
	for(int i=0; i<tamanho; i++){
		if(i == 0){
			letra = tolower(str[0]);
			continue;
		}
		
		if(str[i-1] == ' ' && tolower(str[i]) != letra){		
			return false;
		}
	}
	return true;
}
