#include<iostream>
using namespace std;

int main(){
	int A,B,C;

	while(cin >> A >> B >> C){
		int soma = A+B+C;

		if(soma == 0 or soma == 3)
			cout << "*\n";
		else if(soma == 1){
			if(A == 1)
				cout << "A\n";
			else if(B == 1)
				cout << "B\n";
			else
				cout << "C\n";
		}else if(soma == 2){
			if(A == 0)
				cout << "A\n";
			else if(B == 0)
				cout << "B\n";
			else
				cout << "C\n";
		}

	}

	return 0;
}