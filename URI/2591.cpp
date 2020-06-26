#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    string str;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        int qtd[2] = {0,0}, p=0;
        for(int h=0; h<str.size(); h++){
            if(str[h] == 'a'){
                qtd[p]++;
            }else if(str[h] == 'k'){
                p++;
            }
        }
        cout << 'k';
        for(int h = 0; h<qtd[0] * qtd[1]; h++){
            cout << 'a';
        }
        cout << endl;

    }

    return 0;
}
