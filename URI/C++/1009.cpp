#include<iostream>
#include<string>
using namespace std;

string nome;
double salario,montante,total;

int main(){
	cin>>nome>>salario>>montante;
	total = salario + montante * 0.15;
	
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<"TOTAL = R$ "<<total<<endl;

	return 0;
}
