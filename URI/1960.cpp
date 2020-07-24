#include<iostream>
using namespace std;

int main(){
	int N,aux;
	string str = "";

	cin >> N;

	if(N >= 900){
		str.append("CM");
		N -= 900;
	}else if(N >= 500){
		str.append("D");
		N -= 500;
		aux = N / 100;
		str.append(aux,'C');
		N -= aux*100;
	}else if(N >= 400){
		str.append("CD");
		N -= 400;
	}else if(N >= 100){
		aux = N / 100;
		str.append(aux,'C');
		N -= aux*100;
	}

	if(N >= 90){
		str.append("XC");
		N -= 90;
	}else if(N >= 50){
		str.append("L");
		N -= 50;
		aux = N / 10;
		str.append(aux,'X');
		N -= aux*10;
	}else if(N >= 40){
		str.append("XL");
		N -= 40;
	}else if(N >= 10){
		aux = N / 10;
		str.append(aux,'X');
		N -= aux*10;
	}

	if(N == 9){
		str.append("IX");
	}else if(N >= 5){
		str.append("V");
		N -= 5;
		str.append(N,'I');
	}else if(N == 4){
		str.append("IV");
	}else{
		str.append(N,'I');
	}

	cout << str << endl;
	return 0;
}