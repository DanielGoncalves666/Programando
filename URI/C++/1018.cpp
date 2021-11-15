#include<iostream>
using namespace std;

int main(){
	int N, cem = 0, cinquenta = 0, vinte = 0, dez = 0, cinco = 0, dois = 0, um = 0;

	cin >> N;
	cout << N << endl;

    if(N >= 100){
        cem = N/100;
        N -= cem*100;
    }

    if(N >= 50){
        cinquenta = 1;
        N -= 50;
    }

    if(N >= 20){
        vinte = N/20;
        N -= vinte*20;
    }

    if(N >= 10){
        dez = 1;
        N -= 10;
    }

    if(N >= 5){
        cinco = 1;
        N -= 5;
    }

    if(N >= 2){
        dois = N/2;
        N -= 2*dois;
    }

    if(N%2 == 1){
        um += 1;
    }

    cout << cem << " nota(s) de R$ 100,00\n";
    cout << cinquenta << " nota(s) de R$ 50,00\n";
    cout << vinte << " nota(s) de R$ 20,00\n";
    cout << dez << " nota(s) de R$ 10,00\n";
    cout << cinco << " nota(s) de R$ 5,00\n";
    cout << dois << " nota(s) de R$ 2,00\n";
    cout << um << " nota(s) de R$ 1,00\n";

	return 0;
}