#include<iostream>
using namespace std;

int a,b;

int main(){
	cin >> a >> b;
	if(a == b)
		cout << a << endl;
	else if(a > b)
		cout << a << endl;
	else if(a < b)
		cout << b << endl;

	return 0;
}
