#include<iostream>
using namespace std;

int p1, p2, qtd1, qtd2;
float valor1, valor2;

int main(){
	cin>>p1>>qtd1>>valor1;
	cin>>p2>>qtd2>>valor2;
	
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<"VALOR A PAGAR: R$ "<<qtd1*valor1 + qtd2*valor2<<endl;

	return 0;
}	
