#include<iostream>
using namespace std;

int main(){
	int B,T,area;

	cin >> B >> T;

	if(B == T){
		area = B * 70;
	}else{
		area = (B+T)*35;
	}

	if(area > 5600){
		cout << "1";
	}else if(area == 5600){
		cout << "0";
	}else{
		cout << "2";
	}
	cout << endl;

	return 0;
}