#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N, A, B, C, qtd;
	char simbolo, other;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A >> simbolo >> B >> other >> C;

		if(simbolo == '+'){
			qtd = abs((A + B) - C);
		}else if(simbolo == 'x'){
			qtd = abs((A * B) - C);
		}else if(simbolo == '-'){
			qtd = abs((A - B) - C);
		}

		cout << "E";
		for(int h=0; h<qtd; h++){
			cout << 'r';
		}
		cout << "ou!\n";
	}

	return 0;
}