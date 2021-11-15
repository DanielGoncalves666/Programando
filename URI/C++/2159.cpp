#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N;
	double menor, maior;

	cin >> N;

	menor = N / log(N);
	maior = 1.25506 * (N / log(N));

	cout.precision(1);
	cout.setf(ios::fixed);
	cout << menor << " " << maior << endl;

	return 0;
}