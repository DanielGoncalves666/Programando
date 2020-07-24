#include<iostream>
using namespace std;

int main(){
	int N, min, max, qtd, num;

	while(cin >> N >> min >> max){
		qtd = 0;

		for(int i=0; i<N; i++){
			cin >> num;

			if(num >= min && num <= max)
				qtd++;
		}

		cout << qtd << endl;
	}

	return 0;
}