#include<iostream>
#include<string>
using namespace std;

string str;

int main(){
	getline(cin,str);
	if(str.size() > 80)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
