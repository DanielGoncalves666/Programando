#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,T;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> T;
		int aux = 1,total = T;
		for(int h=1; h<=T; h++){
			if(h == pow(aux,2)){
				total--;
				aux++;
			}
		}
		cout << total << endl;
	}

	return 0;
}