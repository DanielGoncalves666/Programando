#include<iostream>
using namespace std;

int func, horas;
double valor;

int main(){
	cin>>func>>horas>>valor;
	
	cout<<"NUMBER = "<<func<<endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<"SALARY = U$ "<<horas*valor<<endl;

	return 0;
}
