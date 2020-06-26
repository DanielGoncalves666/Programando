#include<iostream>
using namespace std;

int main(){
	int N,A,B;
	for(;;){
		cin >> N;
		if(N == 0)
			break;
		
		int jog1 = 0, jog2 = 0;

		for(int i=0; i<N; i++){
			cin >> A >> B;

			if(A > B){
				jog1++;
			}else if(A < B){
				jog2++;
			}

		}
		cout << jog1 << " " << jog2 << endl;

	}

	return 0;
}