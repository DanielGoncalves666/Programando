#include<iostream>
#include<cmath>
using namespace std;

int N,qtd;

int main(){
	while(cin >> N){
		if(N == 1)
			cout << "0\n";
		else{
			qtd = 0;
			while(N > 1){
				N = N/2;
				qtd++;
			}
			cout << qtd << endl;
		}
	}

	return 0;
}
