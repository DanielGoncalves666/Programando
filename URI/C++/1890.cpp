#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,C,D;
	unsigned int result;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> C >> D;

		if(C+D == 0)
			result = 0;
		else{
			result = pow(26,C);
			result *= pow(10,D);
		}

		cout << result << endl;
	}

	return 0;
}