#include<iostream>
using namespace std;

int main(){
	string origem, para;

	cin >> origem >> para;

	int oL = origem[1];
	int oC = origem[0] - 48;
	int pL = para[1];
	int pC = para[0] - 48;

	if(oL + 3 <= pL || oL - 3 >= pL || oC - 3 >= pC || oC + 3 <= pC){//se estiver fora do alcanse de um movimento
		cout << "INVALIDO" << endl;
	}else if(oL == pL || oC == pC){//se o destino for a mesma linha ou coluna
		cout << "INVALIDO" << endl;
	}else if(pL - oL == pC - oC){//se o destino estiver nas diagonais do cavalo
		cout << "INVALIDO" << endl;
	}else{
		cout << "VALIDO" << endl;
	}

	return 0;
}