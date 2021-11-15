#include<iostream>
#include<cmath>
using namespace std;

const double pi = 3.14159;

double A,B,C;
double triangulo, circulo, trapezio, quadrado, retangulo;

int main(){
	cin >> A >> B >> C;
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << "TRIANGULO: " << (A * C) / 2 << endl;
	cout << "CIRCULO: " << pi * pow(C,2) << endl;
	cout << "TRAPEZIO: " << ((A + B) * C) / 2 << endl;
	cout << "QUADRADO: " << pow(B,2) << endl;
	cout << "RETANGULO: " << A * B << endl;

	return 0;
}
