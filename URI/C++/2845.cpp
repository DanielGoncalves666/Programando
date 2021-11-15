#include<iostream>
using namespace std;

int main(){
	int N,num,maior;

	cin >> N;
	

	for(int i=0; i<N; i++){
		cin >> num;
		
		if(i == 0){
			maior = num;
		}else if(maior < num){
			maior = num;
		}
	}

	cout << maior + 1 << endl;
	
	return 0;
}