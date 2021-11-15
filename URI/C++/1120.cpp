#include<iostream>
using namespace std;

int main(){
	int N;
	string num;
	while(1){
		cin >> N >> num;

		if(N == 0 && num[0] == '0' && num.size() == 1)
			break;

		int soma = 0;
		for(int i=0; i < num.size(); i++){
			if((num[i] - '0') == N)
				continue;
			else{
				soma += num[i] - '0';
				if(soma > 0)
					cout << num[i];
			}		
		}
		if(soma == 0)
			cout << "0";
		
		cout << endl;
	}

	return 0;
}