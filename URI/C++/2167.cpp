#include<iostream>
using namespace std;

int N,num,anterior,queda=0;

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num;
		if(i == 0)
			anterior = num;
		else{
			if(queda == 0 && anterior > num){
				queda = i+1;
			}
			anterior = num;
		}
	}
	cout << queda << endl;

	return 0;
}
