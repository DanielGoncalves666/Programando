#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,X,Y,rafa,beto,carlos;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> X >> Y;

		rafa = pow(3*X,2) + pow(Y,2);
		beto = 2*pow(X,2) + pow(5*Y,2);
		carlos = -100*X + pow(Y,3);

		if(rafa > beto && rafa > carlos)
			cout << "Rafael ganhou\n";
		else if(beto > carlos)
			cout << "Beto ganhou\n";
		else 
			cout << "Carlos ganhou\n";

	}

	return 0;
}