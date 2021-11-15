#include<iostream>
using namespace std;

int main(){
	int N,T;
	string str;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> T;
		int vet[T];
		for(int h=0; h<T; h++){
			cin >> vet[h];
		}
		getline(cin,str);
		cin >> str;

		int qtd = 0;
		for(int h=0; h<T; h++){
			if(vet[h] > 2 && str[h] == 'J')
				qtd++;
			else if(vet[h] < 3 && str[h] == 'S')
				qtd++;
		}
		cout << qtd << endl;
	}

	return 0;
}