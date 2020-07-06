#include<iostream>
using namespace std;

int main(){
	int N,LA,LB,SA,SB;

	cin >> N >> LA >> LB >> SA >> SB;
	
	if(LA<=N && LB>=N){
		if(SA<=N && SB>=N){
			cout << "possivel\n";
		}else{
			cout << "impossivel\n";
		}
	}else{
		cout << "impossivel\n";
	}

	return 0;
}