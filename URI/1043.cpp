#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double A,B,C;

	cin >> A >> B >> C;

	cout.precision(1);
	cout.setf(ios::fixed);

	if(A < B + C && B < A + C && C < A + B && A > abs(B-C) && B > abs(A-C) && C > abs(A-B))
		cout << "Perimetro = " << A + B + C << endl;
	else
		cout << "Area = " << ((A+B)*C)/2.0 << endl;

	return 0;
}