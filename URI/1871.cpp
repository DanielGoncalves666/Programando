#include<iostream>
#include<string>
using namespace std;

int main(){
	int a,b;

	while(true){
		cin >> a >> b;

		if(a+b == 0)
			break;

		int soma = a + b;
		string str = to_string(soma);

		for(int i=0; i< str.size(); i++){
			if(str[i] != '0')
				cout << str[i];
		}
		cout << endl;
	}

	return 0;
}