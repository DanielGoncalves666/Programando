#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;

	while(getline(cin,str)){

		bool inicioIta = true, inicioNeg = true;
		for(int i=0; i< str.size(); i++){
			if(str[i] == '_'){
				if(inicioIta){
					cout << "<i>";
					inicioIta = false;
				}else{
					cout << "</i>";
					inicioIta = true;
				}
			}else if(str[i] == '*'){
				if(inicioNeg){
					cout << "<b>";
					inicioNeg = false;
				}else{
					cout << "</b>";
					inicioNeg = true;
				}
			}else{
				cout << str[i];
			}
		}
		cout << endl;
	}


	return 0;
}