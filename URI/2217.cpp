#include<iostream>
using namespace std;

int main(){
	int N,A;
	
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A;

		if(A % 2 == 0)
			cout << "1" << endl;
		else
			cout << "9" << endl;
	}

	return 0;
}