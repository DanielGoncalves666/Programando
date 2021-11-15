#include<iostream>
using namespace std;

int main(){
	int N,base,num,qtd = 0;
	char simbolo;
	while(true){
		if(N == 0)
			break;
		
		if(qtd != 0)
			cout << endl;

		qtd++;
		cin >> base;
		for(int i=0; i<N-1; i++){
			cin >> simbolo >> num;

			if(simbolo == '+')
				base += num;
			else
				base -= num;
		}

		cout << "Teste " << qtd << endl;
		cout << base << endl;
	}

	return 0;
}