#include<iostream>
#include<string>
using namespace std;

int main(){
	int N, A, B;
	string str;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		size_t pos = str.find('x');
		A = stoi(str,&pos);
		str = str.substr(pos+1);
		B = stoi(str,NULL);

		if(A == B){
			cout << A << " x 5 = " << A*5 << endl;
			cout << A << " x 6 = " << A*6 << endl;
			cout << A << " x 7 = " << A*7 << endl;
			cout << A << " x 8 = " << A*8 << endl;
			cout << A << " x 9 = " << A*9 << endl;
			cout << A << " x 10 = " << A*10 << endl;
		}else{
			cout << A << " x 5 = " << A*5 << " && " << B << " x 5 = " << B*5 << endl;
			cout << A << " x 6 = " << A*6 << " && " << B << " x 6 = " << B*6 << endl;
			cout << A << " x 7 = " << A*7 << " && " << B << " x 7 = " << B*7 << endl;
			cout << A << " x 8 = " << A*8 << " && " << B << " x 8 = " << B*8 << endl;
			cout << A << " x 9 = " << A*9 << " && " << B << " x 9 = " << B*9 << endl;
			cout << A << " x 10 = " << A*10 << " && " << B << " x 10 = " << B*10 << endl;
		}
	}

	return 0;
}