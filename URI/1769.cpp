#include<iostream>
using namespace std;

int main(){
	string cpf;
	while(cin >> cpf){
		int verifica1 = 0, verifica2 = 0;

		int incr1 = 1, incr2 = 9;
		for(int i=0; i<cpf.size()-3;i++){
			if(cpf[i] == '.')
				continue;

			verifica1 += (cpf[i] - '0') * incr1;
			verifica2 += (cpf[i] - '0') * incr2;
			incr1++;
			incr2--;
		}

		verifica1 %= 11;
		verifica2 %= 11;

		if(verifica1 == 10)
			verifica1 -= 10;
		
		if(verifica2 == 10)
			verifica2 -= 10;

		if(verifica1 == cpf[12] - '0' && verifica2 == cpf[13] - '0')
			cout << "CPF valido" << endl;
		else
			cout << "CPF invalido" << endl;
	}

	return 0;
}