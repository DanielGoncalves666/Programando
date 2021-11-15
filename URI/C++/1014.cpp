#include<iostream>
using namespace std;

int dist;
float gasto;

int main(){
	cin >> dist >> gasto;
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << dist / gasto << " km/l\n";
	
	return 0;
}
