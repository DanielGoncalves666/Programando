#include<iostream>
#include<string>
using namespace std;

string str;

int main(){
	getline(cin,str);

	if(str.size() > 140){
		cout << "MUTE" << endl;
	}else
		cout << "TWEET" << endl;


	return 0;
}
