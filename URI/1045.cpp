#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<double> vet;
	double num, A, B, C;

	for(int i=0; i<3; i++){
		cin >> num;
		vet.push_back(num);
	}

	sort(vet.begin(), vet.end());
	C = vet[0];
	B = vet[1];
	A = vet[2];

	if(A >= B + C){
		cout << "NAO FORMA TRIANGULO\n";
	}else{
		if(A * A == B * B + C * C){
			cout << "TRIANGULO RETANGULO\n";
		}else if(A * A > B * B + C * C){
			cout << "TRIANGULO OBTUSANGULO\n";
		}else if(A * A < B * B + C * C){
			cout << "TRIANGULO ACUTANGULO\n";
		}

		if(A == B && B == C){
			cout << "TRIANGULO EQUILATERO\n";
		}else if(A == B || B == C || A == C){
			cout << "TRIANGULO ISOSCELES\n";
		}
	}
	return 0;
}