#include<iostream>
using namespace std;

int main(){
	int N;

	cin >> N;

	if(N % 2 == 0){
		cout << N + 2 << endl;
	}else{
		cout << N + 1 << endl;
	}
}