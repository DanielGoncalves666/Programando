#include<iostream>
using namespace std;

int main(){
	int inicio, fim, total = 0;

	cin >> inicio >> fim;

	if(inicio == fim)
		total = 24;
	else if(inicio < fim)
		total = fim - inicio;
	else
		total = (24 - inicio) + fim;

	cout << "O JOGO DUROU "<< total <<" HORA(S)\n";


	return 0;
}