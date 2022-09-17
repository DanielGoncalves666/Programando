#include<iostream>
using namespace std;

int main(){
	int N,qtd;

	while(true){
		cin >> N;

		if(N == 0)
			break;

		int total;
		for(int i=0; i<N; i++){
			cin >> qtd;

			total = 0;

			if(qtd % 2 == 0){
				total += 2;
				qtd -= 2;
			}else{
				total += 1;
				qtd--;
			}

			total += qtd*2;

			cout << total << endl;
		}
	}

	return 0;
}