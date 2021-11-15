#include<iostream>
using namespace std;

int N;
double raiz;

double div(int repet);

int main(){
	cin >> N;
	raiz = 3.0 + div(N);
	
	cout.precision(10);
	cout.setf(ios::fixed);
	cout << raiz << endl;

	return 0;
}

double div(int repet){
	if(repet == 0)
		return 0;
	else
		return 1.0/(6.0 + div(repet-1));
}
