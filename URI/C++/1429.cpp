#include<iostream>
using namespace std;

int fatorial(int N);

int main(){
	string str;
	int num;

	while(true){
		cin >> str;

		if(str[0] == '0')
			break;

		num = 0;
		for(int i=str.size(),h=0; i>0;i--, h++){
			num += (str[h] - '0') * fatorial(i);
		}

		cout << num << endl;
	}

	return 0;
}

int fatorial(int N){
	int fator = 1;
	
	if(N == 1)
		return 1;
	else{
		return N*fatorial(N-1);
	}
	
}