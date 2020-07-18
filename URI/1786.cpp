#include<iostream>
using namespace std;

int main(){
	string cpf;

	while(cin >> cpf){
		int verifica1 = 0, verifica2 = 0;
		int incr1 = 1, incr2 = 9;
		for(int i=0; i<cpf.size(); i++){
			verifica1 += (cpf[i] - '0') * incr1;
			verifica2 += (cpf[i] - '0') * incr2;
			incr1++;
			incr2--;
		}

		verifica1 %= 11;
		verifica2 %= 11;

		if(verifica1 == 10)
			verifica1 = 0;
		
		if(verifica2 == 10)
			verifica2 = 0;

		cpf.append(1, (char) verifica1 + 48);
		cpf.append(1, (char) verifica2 + 48);
		cpf.insert(9,1,'-');
		cpf.insert(6,1,'.');
		cpf.insert(3,1,'.');

		cout << cpf << endl;
	}


	return 0;
}