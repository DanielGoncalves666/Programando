#include<iostream>
using namespace std;

int main(){
	int N, A, total = 0;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A;
		if(A == 1)
			total++;
	}

	cout << total << endl;

	return 0;
}