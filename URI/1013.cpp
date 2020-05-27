#include<iostream>
using namespace std;

int a,b,c;

int main(){
	cin >> a >> b >> c;

	if(a >= b && a >= c)
		cout << a << " eh o maior\n";
	else if(b >= c && b >= a)
		cout << b << " eh o maior\n";
	else
		cout << c << " eh o maior\n";

	return 0;
}
