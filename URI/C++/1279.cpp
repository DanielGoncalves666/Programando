#include<iostream>
#include<string>
using namespace std;

int somarDigitos(string str);
bool divisivel11(string str);

int main(){
    string ano;
    bool leap,imprimir = false;
    int finale;

    while(cin >> ano){
        bool festival = false;
        int fim = ano.size() - 1;

        finale = 1000*(ano[fim-3] - '0') + 100*(ano[fim-2] - '0');
        finale += 10*(ano[fim-1] - '0') + (ano[fim] - '0');

        if(finale%4 == 0){
            leap = true;
            if(finale%400 == 0){
                leap = true;
            }else if(finale%100 == 0)
                leap = false;
        }else
            leap = false;

        if(imprimir)
            cout << endl;
        else
            imprimir = true;

        if(leap)
            cout << "This is leap year.\n";

        if(somarDigitos(ano)%3 == 0 && finale%5 == 0){
            cout << "This is huluculu festival year.\n";
            festival = true;
        }

        if(divisivel11(ano) && finale%5 == 0 && leap){
            cout << "This is bulukulu festival year.\n";
            festival = true;
        }

        if(!leap && !festival)
            cout << "This is an ordinary year.\n";
    }

    return 0;
}

int somarDigitos(string str){
    int soma = 0;
    for(int i=0; i<str.size(); i++){
        soma += str[i] - '0';
    }
    return soma;
}

bool divisivel11(string str){
    int result = 0;
    int paridade = (str.size() - 1)%2;
    for(int i=str.size()-1; i>=0; i--){
        if(paridade == 0){
            if(i%2 == 0)
                result += str[i] - '0';
            else
                result -= str[i] - '0';
        }else{
            if(i%2 == 0)
                result -= str[i] - '0';
            else
                result += str[i] - '0';
        }
    }
    if(result%11 == 0)
        return true;
    else
        return false;
}
