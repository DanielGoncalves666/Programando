#include<iostream>
using namespace std;

int main(){
	int N,num, pos;
	string str;

	cin >> N;
	while(str.empty()){
		cin >> str;
	}

	pos = str[0] - 'A';

	for(int i=0; i<N; i++){
		cin >> num;

		if(num == 1){
			if(pos == 0)
				pos = 1;
			else if(pos == 1)
				pos = 0;
		}else if(num == 2){
			if(pos == 1)
				pos = 2;
			else if(pos == 2)
				pos = 1;
		}else{
			if(pos == 0)
				pos = 2;
			else if(pos == 2)
				pos = 0;
		}
	}

	cout << (char) (pos + (int) 'A') << endl;

	return 0;
}