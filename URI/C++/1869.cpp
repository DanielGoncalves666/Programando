#include<iostream>
#include<vector>
using namespace std;

int main(){
	unsigned long long N;
	vector<int> vet;

	while(true){
		cin >> N;
		if(N == 0){
			cout << "0" << endl;
			break;
		}

		while(true){
			int aux = N % 32;
			N /= 32;

			if(aux >= 10){
				aux += (int) 'A' - 10;
			}else
				aux += (int) '0';

			vet.insert(vet.begin(),aux);

			if(N == 0){
				break;
			}
		}

		for(int i=0; i<vet.size(); i++){
			cout << (char) vet[i];
		}
		cout << endl;

		vet.clear();
	}

	return 0;
}