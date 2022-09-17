#include<iostream>
using namespace std;

int main(){
	double N;
	int qtd;

	cin >> N;

	cout << "NOTAS:" << endl;

	qtd = N/100;
	N -= qtd*100;
	cout << qtd << " nota(s) de R$ 100.00\n";

	qtd = N/50;
	N -= qtd*50;
	cout << qtd << " nota(s) de R$ 50.00\n";

	qtd = N/20;
	N -= qtd*20;
	cout << qtd << " nota(s) de R$ 20.00\n";

	qtd = N/10;
	N -= qtd*10;
	cout << qtd << " nota(s) de R$ 10.00\n";

	qtd = N/5;
	N -= qtd*5;
	cout << qtd << " nota(s) de R$ 5.00\n";

	qtd = N/2;
	N -= qtd*2;
	cout << qtd << " nota(s) de R$ 2.00\n";

	cout << "MOEDAS:\n";
	
	qtd = N/1;
	N -= qtd * 1;
	cout << qtd << " moeda(s) de R$ 1.00\n";

	N += 0.0005;//gambiarra

	qtd = N/0.50;
	N -= qtd * 0.50;
	cout << qtd << " moeda(s) de R$ 0.50\n";

	qtd = N/0.25;
	N -= qtd * 0.25;
	cout << qtd << " moeda(s) de R$ 0.25\n";

	qtd = N/0.10;
	N -= qtd * 0.10;
	cout << qtd << " moeda(s) de R$ 0.10\n";

	qtd = N/0.05;
	N -= qtd * 0.05;
	cout << qtd << " moeda(s) de R$ 0.05\n";

	qtd = N/0.01;
	N -= qtd * 0.01;
	cout << qtd << " moeda(s) de R$ 0.01\n";

	return 0;
}