#include<iostream>
using namespace std;

int N;
double raiz;

double divi(int repet);

int main(){
	cin >> N;
	raiz = 1.0 + divi(N);
	cout.precision(10);
	cout.setf(ios::fixed);
	cout << raiz << endl;

	return 0;
}

double divi(int repet){
	if(repet == 0)
		return 0;
	else
		return 1.0/(2.0 + divi(repet-1));
}
