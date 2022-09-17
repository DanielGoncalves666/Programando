#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,A,B;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A >> B;

		//usamos logaritmo pois queremos saber o expoente que eleva 10 q dá o numero A^B, pois usamos base 10
		cout << floor(B*log10(A)) + 1 << endl;
	}

	return 0;
}