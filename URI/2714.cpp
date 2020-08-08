#include<iostream>
using namespace std;

int main(){
	int N;
	string str;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;

		if(str.size() != 20){
			cout << "INVALID DATA" << endl;
			continue;
		}

		if(str[0] != 'R' || str[1] != 'A'){
			cout << "INVALID DATA" << endl;
			continue;		
		}

		size_t pos = string::npos;
		pos = str.find_first_of("123456789");

		if(pos == string::npos){
			cout << "INVALID DATA" << endl;
			continue;
		}

		for(int h = pos; h<str.size(); h++){
			cout << str[h];
		}
		cout << endl;
	}

	return 0;
}