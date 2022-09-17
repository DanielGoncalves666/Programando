#include<iostream>
#include<string>
using namespace std;

string nome;

int main(){
	for(int i=0; i<10; i++){
		cin >> nome;
		if(i == 2 || i == 6 || i == 8)
			cout << nome << endl;
	}

	return 0;
}
