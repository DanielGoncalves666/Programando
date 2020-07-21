#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,a,b,c;
	double delta, result;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> a >> b >> c;
		delta = pow(b,2) - 4 * a * c;
		result = -delta / (4.0 * a);

		cout.precision(2);
		cout.setf(ios::fixed);
		cout << result << endl;
	}

	return 0;
}