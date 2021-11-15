#include<iostream>
using namespace std;

int L,C;

int main(){
	cin >> L >> C;
	
	if(L%2 == 0 && C%2 == 0)
		cout << 1 << endl;
	else if(L%2 == 0 && C%2 == 1)
		cout << 0 << endl;
	else if(L%2 == 1 && C%2 == 0)
		cout << 0 << endl;
	else if(L%2 == 1 && C%2 == 1)
		cout << 1 << endl;


	return 0;
}
