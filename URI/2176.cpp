#include<iostream>
#include<string>
using namespace std;

string str;
int qtd = 0;

int main(){
	cin >> str;
	for(int i=0; i<str.size(); i++){
		if(str[i] == '1')
			qtd++;
	}
	if(qtd%2 == 0)
		str += '0';
	else
		str += '1';
		
	cout << str << endl;
	
	return 0;
}
