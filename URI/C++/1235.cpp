#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	string str;
	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		getline(cin,str);
		int meio = str.size() / 2;
		for(int h = meio - 1; h >= 0; h--){
			cout << str[h];
		}

		for(int h = str.size() - 1; h >= meio; h--){
			cout << str[h];
		}
		cout << endl;
	}

	return 0;
}