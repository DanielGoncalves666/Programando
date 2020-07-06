#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	string str;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		getline(cin,str);

		bool primeira = true;
		for(int h=0; h< str.size(); h++){
			if(h == 0){
				if(str[h] != ' '){
					cout << str[h];
					primeira = false;
				}else{
					int espacos=0;
					for(int j=0; j<str.size(); j++){
						if(str[j] != ' '){
							cout << str[j];
							h = j;
							primeira = false;
							break;
						}else{
							espacos++;
						}
					}

					if(espacos == str.size()){
						break;
					}
				}
			}else if(str[h] == ' '){
				primeira = true;
			}else if(str[h] != ' ' && primeira){
				cout << str[h];
				primeira = false;
			}
		}
		cout << endl;
	}

	return 0;
}