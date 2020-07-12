#include<iostream>
using namespace std;

int main(){
	int N, A, B;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> A >> B;

		int soma = 0;

		for(int h=0; h<B; h++){
			if(h == 0){
				if(A % 2 == 1){
					soma += A;
				}else{
					A += 1;
					soma += A;
				}
			}else{
				soma += A;
			}

			A += 2;
		}

		cout << soma << endl;
	}

	return 0;
}