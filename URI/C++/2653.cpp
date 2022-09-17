#include<iostream>
using namespace std;

int main(){
	string str = "", aux;
	int total = 0;

	while(cin >> aux){
		aux = " "  + aux + " ";
		int pos = str.find(aux,0);

		if(pos == string::npos){
			total++;
			str.append(aux);
		}
	}

	cout << total << endl;

	return 0;
}