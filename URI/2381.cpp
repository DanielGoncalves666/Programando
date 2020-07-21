#include<iostream>
using namespace std;

int main(){
	int N,K;

	cin >> N >> K;
	string str[N];
	getline(cin,str[0]);

	for(int i=0; i<N; i++){
		cin >> str[i];
	}

	for(int i=0; i<N-1;i++){
		for(int h=0;;h++){
			if(str[i].size() == h){//foi totalmente verificado
				break;
			}else if(str[i+1].size() == h){//foi totalmente verificado
				swap(str[i],str[i+1]);
				i = -1;
				break;
			}else if(str[i][h] == str[i+1][h]){
				continue;
			}else if(str[i][h] > str[i+1][h]){
				swap(str[i],str[i+1]);
				i = -1;
				break;
			}else{
				break;
			}
		}
	}

	cout << str[K-1] << endl;

	return 0;
}