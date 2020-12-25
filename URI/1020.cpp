#include<iostream>
using namespace std;

int main(){
	int dias, anos, meses;

	cin >> dias;

	anos = dias / 365;
	dias -= anos * 365;

	meses = dias / 30;
	dias -= meses * 30;

	cout << anos << " ano(s)" << endl;
	cout << meses << " mes(es)" << endl;
	cout << dias << " dia(s)" << endl;

	return 0;
}