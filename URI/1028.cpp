#include<iostream>
using namespace std;

int main(){
    int N,F1,F2;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> F1 >> F2;

        if(F1 == F2)//eles trocam todas as cartas
            cout << F1 << endl;
        else{
            int R0, R1, R2;
            if(F1 > F2){
                R0 = F1;
                R1 = F2;
            }else{
                R0 = F2;
                R1 = F1;
            }

            while(true){
                R2 = R0 % R1;//o resto da divisao do maior pelo menor

                if(R2 == 0){
                    cout << R1 << endl;
                    break;
                }

                R0 = R1;
                R1 = R2;
            }
        }
    }

    return 0;
}
