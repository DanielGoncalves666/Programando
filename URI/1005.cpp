#include<iostream>
using namespace std;

double a,b,media;

int main(){
	cin>>a>>b;
	
	media = (a*3.5 + b*7.5)/ 11.0;
	
	cout.precision(5);
	cout.setf(ios::fixed);
	cout<<"MEDIA = "<<media<<endl;

	return 0;
}
