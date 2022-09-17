#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,K;
    string str,armazenar;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> K;
        int ok = 0;
        for(int h=0; h<K; h++){
            cin >> str;

            if(h == 0)
                armazenar = str;
            else if(str.compare(armazenar) != 0)
                ok++;
        }

        if(ok != 0)
            cout << "ingles" << endl;
        else
            cout << armazenar << endl;

    }

    return 0;
}
