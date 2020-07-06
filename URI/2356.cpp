#include<iostream>
#include<string>
using namespace std;

int main(){
	string A,B;
	while(cin >> A >> B){
		if(A.find(B,0) != string::npos)
			cout << "Resistente" << endl;
		else
			cout << "Nao resistente" << endl;
	}

	return 0;
}