#include<iostream>
using namespace std;

int main(){
	float vet[] = {4.00,4.50,5.00,2.00,1.50};
	int N, qtd;

	cin >> N >> qtd;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Total: R$ " << vet[N-1] * qtd << endl;

	return 0;
}