#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	string A,B;

	cin >> N;
	getchar();
	for(int i=0; i<N; i++){
		cin >> A >> B;
		int ok = 1;
		if(A.size() < B.size())
			cout << "nao encaixa\n";
		else{
			int j = B.size() - 1;
			for(int h = A.size() - 1; h > A.size() - B.size() - 1; h--, j--){
				if(A[h] != B[j]){
					cout << "nao encaixa\n";
					ok = 0;
					break;
				}
			}
			if(ok == 1)
				cout << "encaixa\n";
		}
	}

	return 0;
}