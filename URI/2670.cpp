#include<iostream>
using namespace std;

int main(){
	int A,B,C,total = 0,aux;

	cin >> A >> B >> C;

	total = A*0 + B*2 + C*4;//maquina no primeiro andar

	aux = A*2 + B*0 + C*2;//maquina no segundo andar
	if(total > aux){
		total = aux;
	}

	aux = A*4 + B*2 + C*0;//maquina no terceiro andar
	if(total > aux){
		total = aux;
	}

	cout << total << endl;

	return 0;
}