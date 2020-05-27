#include<iostream>
#include<cmath>
#define pi 3.14159
using namespace std;

double raio,area;

int main(){
	cin>>raio;

	area = pi * pow(raio,2);
	
	cout.precision(4);
	cout.setf(ios::fixed);
	cout<<"A="<<area<<endl;

	return 0;
}
