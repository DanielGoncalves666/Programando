#include<iostream>
using namespace std;

int main(){
	int a,b,c;

	cin >> a >> b >> c;

	if(a == b || b == c || a == c)//usando dois creditos
		cout << "S" << endl;
	else{
		if(a + b == c || a + c == b || b + c == a)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}