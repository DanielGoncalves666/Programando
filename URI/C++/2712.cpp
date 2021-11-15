#include<iostream>
#include<cctype>
using namespace std;

int main(){
	int N;
	string str, dias[5] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"};

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;

		bool ok = true;
		if(str.size() != 8  || str[3] != '-'){
			cout << "FAILURE" << endl;
		}else{
			for(int h=0; h<3; h++){
				if(isalpha(str[h]) && isupper(str[h])){
					continue;
				}else{
					ok = false;
					break;
				}
			}

			for(int h=4; h<8; h++){
				if(isdigit(str[h])){
					continue;
				}else{
					ok = false;
					break;
				}
			}

			if(!ok){
				cout << "FAILURE" << endl;
			}else{
				int aux = str[7] - '0';
				switch(aux){
					case 1:
					case 2:
						cout << dias[0] << endl;
						break;
					case 3:
					case 4:
						cout << dias[1] << endl;
						break;
					case 5:
					case 6:
						cout << dias[2] << endl;
						break;
					case 7:
					case 8:
						cout << dias[3] << endl;
						break;
					case 9:
					case 0:
						cout << dias[4] << endl;
						break;
				}
			}
		}
	}

	return 0;
}