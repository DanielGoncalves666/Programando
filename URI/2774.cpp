#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	int H,M;
	double num;

	while(cin >> H >> M){

		int N = floor(H*60 / M);

		vector<double> vet;
		
		double media = 0;
		for(int i=0; i<N; i++){
			cin >> num;
			vet.push_back(num);
			media += vet[i];
		}

		media /= N;

		double somatorio = 0;
		for(int i=0; i<N; i++){
			somatorio += (vet[i] - media) * (vet[i] - media);
		}

		double precisao = sqrt(somatorio/(N-1));

		cout.precision(5);
		cout.setf(ios::fixed);
		cout << precisao << endl;

		vet.clear();
	}

	return 0;
}