#include<iostream>
using namespace std;

int main(){
	int um[5],aux,sim=1;;

	for(int i=0; i<5; i++){
		cin >> um[i];
	}

	for(int i=0; i<5; i++){
		cin >> aux;
		um[i] += aux;
	
		if(um[i] == 0 || um[i] == 2)
			sim = 0;
	}

	if(sim == 1)
		cout << "Y\n";
	else
		cout << "N\n";

	return 0;
}