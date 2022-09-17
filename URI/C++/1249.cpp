#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
	string str;

	while(getline(cin, str)){
		for(int i=0; i<str.size(); i++){
			if(isalpha(str[i])){
				if(islower(str[i])){
					int letra = str[i] - 96 + 13;

					if(letra > 26)
						letra -= 26;

					cout << (char) (letra + 96);
				}
				if(isupper(str[i])){
					int letra = str[i] - 64 + 13;

					if(letra > 26)
						letra -= 26;

					cout << (char) (letra + 64);
				}

			}else
				cout << str[i];
		}

		cout << endl;
	}

	return 0;
}