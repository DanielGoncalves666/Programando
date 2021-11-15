#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;

	while(getline(cin, str)){
		if(str.empty())
			cout << endl;

		int strNum[str.size()], tamanho = 0, espacos = 0;
		for(int i=0; i<str.size(); i++){
			if(str[i] != ' '){
				strNum[i - espacos] = str[i];
				tamanho++;
			}else
				espacos++;
		}

		for(int i=0; i < tamanho - 1; i++){
			if(strNum[i] > strNum[i+1]){
				int aux = strNum[i];
				strNum[i] = strNum[i+1];
				strNum[i+1] = aux;
				i = -1;
			}
		}

		bool first = true;
		for(int i=0; i< tamanho; i++){
			if(first == true){
				cout << (char) strNum[i] << ":";
				first = false;

				if(i == tamanho - 1)
					cout << (char) strNum[i] << endl;

			}else{
				if(i == tamanho - 1){
					if(strNum[i] >= strNum[i-1] + 2){
						cout << (char) strNum[i-1] << ", ";
						cout << (char) strNum[i] << ":";
					}

					cout << (char) strNum[i] << endl;
				}else if(strNum[i] >= strNum[i-1] + 2){
					cout << (char) strNum[i-1] << ", ";
					cout << (char) strNum[i] << ":";
				}
			}
		}
	}

	return 0;
}