#include<iostream>
using namespace std;

int main(){
	int A,B;

	cin >> A >> B;

	if(B >= 0 && B <= 2)
		cout << "nova\n";
	else if(B >= 97 && B <=100)
		cout << "cheia\n";
	else if(A < B)
		cout << "crescente\n";	
	else if(A > B)
		cout << "minguante\n";

	return 0;
}