#include<iostream>
using namespace std;

int T,bonus;
int A1,A2,D1,D2,L1,L2;

int main(){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> bonus;
		cin >> A1 >> D1 >> L1;
		cin >> A2 >> D2 >> L2;
		
		int golpe1 = (A1+D1)/2;
		int golpe2 = (A2+D2)/2;
		
		if(L1%2 == 0)
			golpe1 += bonus;
			
		if(L2%2 == 0)
			golpe2 += bonus;
			
		if(golpe1 == golpe2)
			cout << "Empate" << endl;
		else if(golpe1 > golpe2)
			cout << "Dabriel" << endl;
		else
			cout << "Guarte" << endl;
	}

	return 0;
}
