#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int A,B,C;

	for(;;){
		cin >> A >> B >> C;
		if(A + B + C == 0)
			break;
		
		long long int mult = A * B * C;

		cout.precision(0);
		cout.setf(ios::fixed);
		cout << trunc(cbrt(mult)) << endl;
	}

	return 0;
}