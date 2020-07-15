#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        int R = str.find('R');
        int L = str.find('L');
        int J = str.find('J');
        int mais = str.find('+');
        int igual = str.find('=');
        int num1, num2;

        if(R != string::npos){
            num1 = stoi(str.substr(mais+1,(igual-1) - mais));//começa depois do +  L
            num2 = stoi(str.substr(igual+1,string::npos));//começa depois do =     J
            cout << num2 - num1 << endl;
        }else if(L != string::npos){
            num1 = stoi(str.substr(0,mais));//começa no inicio da string           R
            num2 = stoi(str.substr(igual+1,string::npos));//começa depois do =     J
            cout << num2 - num1 << endl;
        }else if(J != string::npos){
            num1 = stoi(str.substr(0,mais));//começa no inicio da string           R
            num2 = stoi(str.substr(mais+1,(igual-1) - mais));//começa depois do +  L
            cout << num1 + num2 << endl;
        }
    }

    return 0;
}
