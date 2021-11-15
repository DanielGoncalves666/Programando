#include<iostream>
#include<cmath>
using namespace std;

bool forma_triangulo(int a,int b, int c);

int main(){
	int a,b,c,d;

	cin >> a >> b >> c >> d;

	if(forma_triangulo(a,b,c)){
		cout << "S" << endl;
	}else if(forma_triangulo(a,b,d)){
		cout << "S" << endl;
	}else if(forma_triangulo(a,c,d)){
		cout << "S" << endl;
	}else if(forma_triangulo(b,c,d)){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}

	return 0;
}

bool forma_triangulo(int a,int b, int c){
	if(a > b + c || b > a + c || c > b + c)
		return false;

	if(abs(b-c) >= a || abs(a-c) >= b || abs(a-b) >= c)
		return false;

	return true;
}