#include<iostream>
#include<string>
using namespace std;

string frase;

int main(){
	getline(cin,frase);
	for(int i=0; i<frase.size(); i++){
		if(frase[i] == ','){
			frase[i] = '\n';
			break;
		}
	}
	cout << frase << endl;

	return 0;
}
