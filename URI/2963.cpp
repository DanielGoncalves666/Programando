#include<iostream>
using namespace std;

int main(){
	int N,num;
	cin >> N;

	int Carlos = 0;
	for(int i=0; i<N; i++){
		cin >> num;

		if(Carlos == -1)
			continue;

		if(i == 0)
			Carlos = num;
		else if(Carlos < num){
			Carlos = -1;
			cout << "N" << endl;
		}
	}

	if(Carlos != -1)
		cout << "S" << endl;

	return 0;
}