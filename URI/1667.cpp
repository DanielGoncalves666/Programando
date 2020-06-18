#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    int linha = 0;
    while(cin >> str){
        linha += str.size();
        if(linha <= 80){
            cout << str;
        }

    }
}
