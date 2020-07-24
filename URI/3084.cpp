#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int hora, minuto;

	while(cin >> hora >> minuto){
		int h = hora / 30;
		int m = (minuto / 30) * 5 + ((minuto % 30)/6);

		printf("%02d:%02d\n",h,m);
	}
	return 0;
}