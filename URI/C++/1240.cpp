#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int N;
	string str1, str2;

	cin >> N;
	getchar();

	for(int i=0;i<N;i++){
		cin >> str1 >> str2;

		if(str1.size() < str2.size())
			cout << "nao encaixa" << endl;
		else{
			int position = str1.rfind(str2);

			if(position + str2.size() == str1.size())
				cout << "encaixa" << endl;
			else
				cout << "nao encaixa" << endl;
		}
	}

	return 0;
}