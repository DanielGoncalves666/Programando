#include<iostream>
using namespace std;

int main(){
	double A,G,Ra,Rg;
	
	cin >> A >> G >> Ra >> Rg;

	if(A == G && Ra == Rg)
		cout << "G" << endl;
	else{
		double mmc = Ra * Rg;
		Ra = mmc / Ra;
		Rg = mmc / Rg;

		if(Ra * A < Rg * G)
			cout << "A" << endl;
		else
			cout << "G" << endl;
	}

	return 0;
}