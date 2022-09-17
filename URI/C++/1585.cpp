#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N,x,y;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> x >> y;

		cout << floor((x*y)/2.0) <<  " cm2" << endl;
	}

	return 0;
}