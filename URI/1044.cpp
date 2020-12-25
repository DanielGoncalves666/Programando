#include<iostream>
using namespace std;

int main(){
	int a,b;

	cin >> a >> b;

	if(a > b){
		int aux = a;
		a = b;
		b = aux;
	}

	if(b % a == 0)
		cout << "Sao Multiplos" << endl;
	else
		cout << "Nao sao Multiplos" << endl;

	return 0;
}