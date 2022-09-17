#include<iostream>
using namespace std;

int main(){
	int N,x,y;
	string str = " ";

	cin >> N;

	int vet[N][N];
	for(int i=0; i<N; i++){
		for(int h=0; h<N; h++){
			cin >> vet[i][h];
		}
	}

	int qtd = 0;
	for(int i=0; i<N*2; i++){
		cin >> x >> y;

		string aux = " " + to_string(vet[x-1][y-1]) + " ";
		if(str.find(aux) == string::npos){
			str.append(to_string(vet[x-1][y-1]));
			str.append(1,' ');
			qtd++;
		}
	}

	cout << qtd << endl;

	return 0;
}