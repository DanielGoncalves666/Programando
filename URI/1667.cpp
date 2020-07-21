#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str;
    int linha = 0;

    while(cin >> str){
        if(str.compare("<br>") == 0){
            cout << endl;
            linha = 0;
            continue;
        }

        if(str.compare("<hr>") == 0){
            if(linha > 0)
                cout << endl;

            for(int i=0; i<8; i++){
                cout << "----------";//imprime os 80 traços
            }
            cout << endl;
            linha = 0;
            continue;
        }

        if(linha + str.size() + 1 <= 80){//o 1 vem do espaço
            if(linha > 0){//se a linha já tiver uma palavra, imprime uma palavra pra separar elas.
                cout << " ";
            }

            cout << str;
            linha += str.size() + 1;//o 1 vem do espaço
        }else{
            cout << endl;//o limite da linha foi batido, começamos uma nova
            cout << str;//e então imprimimos a palavra;
            linha = str.size();//e agora a linha vai ter a quantidade de caracteres da palavra
        }
    }

    if(linha != 0)//se for zero significa que uma quebra de linha no final já foi dada
        cout << endl;

    return 0;
}