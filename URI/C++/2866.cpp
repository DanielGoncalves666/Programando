#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	int N;
	string str;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		cin >> str;

		for(int h = str.size() - 1; h>=0; h--){
			if(islower(str[h]))
				cout << str[h];
		}

		cout << endl;
	}

	return 0;
}