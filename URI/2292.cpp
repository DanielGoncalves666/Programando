#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	unsigned long long int C;
	string str;
	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		cin >> str >> C;

		for(int j=0; j<str.size(); j++){
			if(C % 2 == 0){
				//permanece igual
				C = C / 2;
			}else if(C % 2 == 1){
				//inverte
				if(str[j] == 'X'){
					str[j] = 'O';
					C = (C - 1) / 2;
				}else if(str[j] == 'O'){
					str[j] = 'X';
					C = (C + 1) / 2;
				}
			}
		}
		
		cout << str << endl;
	}

	return 0;
}
