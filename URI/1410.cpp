#include<iostream>
using namespace std;

int main(){
	int A, D, menorA, num, menor1D, menor2D;

	while(1){
		cin >> A >> D;
		if(A+D == 0)
			break;

		for(int i=0; i<A; i++){
			cin >> num;

			if(i == 0)
				menorA = num;
			else if(menorA > num)
				menorA = num;
		}

		for(int i=0; i<D; i++){
			cin >> num;

			if(i == 0)
				menor1D = num;
			else if(menor1D >= num){
				menor2D = menor1D;
				menor1D = num;
			}else if(i == 1)
				menor2D = num;
			else if(menor2D > num)
				menor2D = num;
		}

		if(menor1D == menor2D){
			if(menorA >= menor1D)
				cout << "N\n";
			else
				cout << "Y\n";
		}else{
			if(menorA >= menor2D)
				cout << "N\n";
			else
				cout << "Y\n";
		}
	}

	return 0;
}
