#include<iostream>
using namespace std;

int main(){
	int N, total = 0, num, anterior;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> num;
		
		if(i == 0){
			anterior = num;
			total++;
		}else if(num != anterior){
			anterior = num;
			total++;
		}
	}

	cout << total << endl;

	return 0;
}