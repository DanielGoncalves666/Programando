#include<iostream>
#include<cmath>
using namespace std;

const double pi = 3.14159;

int raio;
double volume;

int main(){
	cin >> raio;
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << "VOLUME = " << (4.0/3) * pi * pow(raio,3) << endl;

	return 0;
}
