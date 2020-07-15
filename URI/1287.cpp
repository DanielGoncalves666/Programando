#include<iostream>
#include<cstring>
#include<cctype>
#include<stdexcept> 
using namespace std;

int main(){
	string str;

	while(getline(cin,str)){
		if(str.empty()){
			cout << "error" << endl;
			continue;
		}

		int num = str.size(), not_okay = 0;
		for(int i=0; i<num; i++){
			if(str[i] == ',' || str[i] == ' '){
				str.erase(i,1);//remove as virgulas e espaços
				i--;
				num--;

				if(str.empty()){
					cout << "error" << endl;
					not_okay = 1;
					break;
				}

				continue;
			}else if(str[i] == 'o' || str[i] == 'O'){
				str[i] = '0';
			}else if(str[i] == 'l'){
				str[i] = '1';
			}else if(isdigit(str[i]) == 0){
				cout << "error" << endl;
				not_okay = 1;
				break;
			}
		}
		
		if(not_okay == 1)
			continue;
		
		long long number;

		try{
			number = stoll(str);
		}catch(out_of_range){
			cout << "error" << endl;
			continue;
		}

		if(number > 2147483647){
			cout << "error" << endl;
			continue;
		}

		cout << number << endl;
	}

	return 0;
}