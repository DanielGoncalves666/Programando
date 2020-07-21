#include<iostream>
using namespace std;

int main(){
	int N;
	string palavra1, palavra2, secreta;

	cin >> N;
	getline(cin,palavra1);

	for(int i=0; i<N; i++){
		cin >> palavra1 >> palavra2 >> secreta;

		int first = secreta.find('_'), last = secreta.rfind('_');

		if(palavra1[first] == palavra2[last] || palavra1[last] == palavra2[first])
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}