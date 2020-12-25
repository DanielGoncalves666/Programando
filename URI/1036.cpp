#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double A, B, C, delta, R1, R2;

	cin >> A >> B >> C;

	delta = (B * B) - 4 * A * C;

	if(delta < 0.0 || A == 0.0){
		cout << "Impossivel calcular" << endl;
	}else{
		R1 = (-B + sqrt(delta))/ (2 * A);
		R2 = (-B - sqrt(delta))/ (2 * A);

		cout.precision(5);
		cout.setf(ios::fixed);
		cout << "R1 = " << R1 << endl;
		cout << "R2 = " << R2 << endl;
	}

	return 0;
}