#include<iostream>
using namespace std;

int main(){
	int N,M,X,qtd=0;

	cin >> N >> M;
	
	for(int i=0; i<N; i++){

		int zeros = 0;
		for(int h=0; h<M; h++){
			cin >> X;

			if(X == 0)
				zeros++;
		}
		if(zeros == 0)
			qtd++;
	}

	cout << qtd << endl;

	return 0;
}