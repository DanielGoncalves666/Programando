#include<iostream>
#include<cmath>
using namespace std;

int N;

int main(){
	while(cin >> N){
		if(N % 100 == 0)
			cout << N/100 << endl;
		else
			cout << (int) floor(N/100)+1 << endl;
	}

	return 0;
}
