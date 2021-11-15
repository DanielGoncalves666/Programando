#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	string str;

	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		cin >> str;
		int total = 1;
		for(int j=0; j<str.size(); j++){
			if(str[j] == 'A' || str[j] == 'a')
				total *= 3;
			else if(str[j] == 'E' || str[j] == 'e')
				total *= 3;
			else if(str[j] == 'I' || str[j] == 'i')
				total *= 3;
			else if(str[j] == 'O' || str[j] == 'o')
				total *= 3;
			else if(str[j] == 'S' || str[j] == 's')
				total *= 3;
			else
				total *= 2;
		}
		cout << total << endl;
	}


	return 0;
}