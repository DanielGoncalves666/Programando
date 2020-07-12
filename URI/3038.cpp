#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string str;

	while(getline(cin,str)){
		for(int i=0; i<str.size(); i++){
			if(str[i] == '@')
				cout << "a";
			else if(str[i] == '&')
				cout << "e";
			else if(str[i] == '!')
				cout << "i";
			else if(str[i] == '*')
				cout << "o";
			else if(str[i] == '#')
				cout << "u";
			else
				cout << str[i];
		}
		cout << endl;
	}

	return 0;
}