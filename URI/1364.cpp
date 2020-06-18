//incompleto
#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,M,value,qtd;
    for(;;){
        cin >> N >> M;
        if(N + M == 0)
            break;

        string emot[N],str[M];

        for(int i=0; i<N; i++){
            cin >> emot[i];
        }

        qtd = 0;
        for(int i=0; i<M; i++){
            getline(cin,str[i]);
            cin.clear();
            for(int j=0; j<N; j++){
                for(int h=0; h<str[i].size() - (emot[j].size() - 1);h++){
                    value = str[i].find(emot[j],h);
                    if(value == string::npos)
                        break;
                    else{
                        str[i][value + (emot[j].size() - 1)] = ' ';
                        cout << str[i] << endl;
                        qtd++;
                    }
                }
            }
        }
        cout << qtd << endl;

    }

    return 0;
}
