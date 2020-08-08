#include<iostream>
using namespace std;

int main(){
	long long int N;

	cin >> N;

	long long int qtd_diagonais = (N * (N - 3))/2;

	cout << qtd_diagonais << endl;

	return 0;
}