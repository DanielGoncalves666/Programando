#include<iostream>
using namespace std;

string str;

int main(){
    while(getline(cin,str)){
        if(str.compare("esquerda") == 0)
            cout << "ingles" << endl;
        else if(str.compare("direita") == 0)
            cout << "frances" << endl;
        else if(str.compare("nenhuma") == 0)
            cout << "portugues" << endl;
        else if(str.compare("as duas") == 0){
            cout << "caiu" << endl;
        }
    }
    return 0;
}
