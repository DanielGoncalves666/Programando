#include<iostream>
using namespace std;

int main(){
	
	int L,R;
	
	for(;;){
		cin >> L >> R;
		if(L + R == 0)
			break;
			
		cout << L + R << endl;

	}
	
	return 0;
}
