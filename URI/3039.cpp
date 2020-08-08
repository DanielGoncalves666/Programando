#include<iostream>
using namespace std;

int main(){
	int N, meninos = 0, meninas = 0;
	string str, letra;
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str >> letra;

		if(letra.compare("F") == 0)
			meninas++;
		else
			meninos++;
	}

	cout << meninos << " carrinhos" << endl;
	cout << meninas << " bonecas" << endl;

	return 0;
}