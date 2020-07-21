#include<iostream>
using namespace std;

int main(){
	int a,b;

	while(true){
		cin >> a >> b;

		if(a + b == 0)
			break;

		if(a == b){
			cout << a << endl;
			continue;
		}

		int c = 2*a - b;
		/*menor para o maior: c a b
		mediana = a e media = mediana
		media -> a = (a+b+c)/3
		3a = a+b+c
		c = 2a -b
		*/
		cout << c << endl;
	}
	return 0;
}