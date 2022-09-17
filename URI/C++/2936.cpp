#include<iostream>
using namespace std;

int main(){
	int C,B,Bo,M,I,soma;
	cin >> C >> B >> Bo >> M >> I;
	soma = C * 300 + B * 1500 + Bo * 600 + M * 1000 + I * 150 + 225;
	cout << soma << endl;
	return 0;
}
