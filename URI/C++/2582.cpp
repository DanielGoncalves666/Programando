#include<iostream>
using namespace std;

int N,a,b;

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a >> b;
		if(a+b == 0)
			cout << "PROXYCITY" << endl;
		else if(a+b == 1)
			cout << "P.Y.N.G." << endl;
		else if(a+b == 2)
			cout << "DNSUEY!" << endl;
		else if(a+b == 3)
			cout << "SERVERS" << endl;
		else if(a+b == 4)
			cout << "HOST!" << endl;
		else if(a+b == 5)
			cout << "CRIPTONIZE" << endl;
		else if(a+b == 6)
			cout << "OFFLINE DAY" << endl;
		else if(a+b == 7)
			cout << "SALT" << endl;
		else if(a+b == 8)
			cout << "ANSWER!" << endl;
		else if(a+b == 9)
			cout << "RAR?" << endl;
		else if(a+b == 10)
			cout << "WIFI ANTENNAS" << endl;
	}

	return 0;
}
