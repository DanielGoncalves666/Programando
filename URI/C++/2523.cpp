#include<iostream>
#include<string>
using namespace std;

string str;
int N,letra;

int main(){
	while(cin >> str){
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> letra;
			cout << str.at(letra - 1);
		}
		cout << endl;
	}

	return 0;
}
