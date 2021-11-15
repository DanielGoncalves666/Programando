#include<iostream>
#include<cmath>
using namespace std;

int primo(int num);

int main(){
	int N,M,P1,P2;

	cin >> N >> M;

	P1 = primo(N);
	P2 = primo(M);

	cout << P1* P2 << endl;

	return 0;
}

int primo(int num){

	for(int i=num; i>1; i--){
		if(i == 2)
			return 2;
		else if(i % 2 == 0)
			continue;

		for(int h=3;; h += 2){
			if(h > sqrt(i))
				return i;
			else if(i % h == 0)
				break;
		}
	}
}