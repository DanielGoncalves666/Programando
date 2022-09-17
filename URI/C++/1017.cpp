#include<iostream>
using namespace std;

int main(){
	int H, V;
	double distancia, litros;

	cin >> H >> V;

	distancia = H * V;
	litros = distancia / 12;

	cout.precision(3);
	cout.setf(ios::fixed);
	cout << litros << endl;

	return 0;
}