#include<iostream>
using namespace std;

int main(){
	int T,N;
	string K;

	cin >> T;
	getline(cin,K);
	for(int i=0; i<T; i++){
		cin >> N >> K;

		unsigned long long int fatorial = 1; 
		for(int h = 0;; h++){
			int aux = N - (K.size()*h);
			if(aux <= 0)//nao sei pq diabos n da pra colocar a expressao direito aqui
				break;

			fatorial *= N-(K.size() * h);
		}

		cout << fatorial << endl;
	}

	return 0;
}