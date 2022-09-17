#include<iostream>
using namespace std;

int main(){
	string str;

	cin >> str;

	int pendentes = 0;
	for(int i=0; i<str.size(); i++){
		if(str[i] == ')'){
			if(pendentes > 0){
				pendentes--;
			}
		}else{
			pendentes++;
		}
	}

	if(pendentes == 0){
		cout << "Partiu RU!" << endl;
	}else{
		cout << "Ainda temos " << pendentes << " assunto(s) pendente(s)!" << endl;
	}


	return 0;
}