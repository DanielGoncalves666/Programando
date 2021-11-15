#include<iostream>
using namespace std;

int main(){
	string A, B;

	cin >> A >> B;

	for(int i=0;;i++){

		if(A[i] == B[i]){
			if(i + 1 == A.size()){
				cout << A << endl << B << endl;
				break;
			}else if(i + 1 == B.size()){
				cout << B << endl << A << endl;
				break;
			}

			continue;
		}else if(A[i] < B[i]){
			cout << A << endl << B << endl;
			break;
		}else{
			cout << B << endl << A << endl;
			break;
		}

	}
}