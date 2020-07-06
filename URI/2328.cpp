#include<iostream>
using namespace std;

int main(){
	int N,D,pedacos=0;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> D;
		pedacos += D - 1;
	}

	cout << pedacos << endl;

	return 0;
}