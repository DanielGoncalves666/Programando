#include<iostream>
using namespace std;

int main(){
	int total = 0, num;
	string str[9] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

	for(int i=0; i<9; i++){
		cin >> num;
		total += num;
	}

	int index = (total % 9);

	if(index == 0)
		index = 8;
	else
		index --;

	cout << str[index] << endl;


	return 0;
}