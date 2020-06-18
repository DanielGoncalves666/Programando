#include<iostream>
#include<string>
using namespace std;

int N,M;
string str;

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		cin >> str;
		if(str.compare("fechou") == 0)
			N++;
		if(str.compare("clicou") == 0)
			N--;
	}
	cout << N << endl;

	return 0;
}
