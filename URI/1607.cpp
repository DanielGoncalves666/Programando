#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    string A,B;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A >> B;
        int tamanho = A.size();
        int qtd = 0;

        for(int h=0; h<tamanho; h++){
            while(A[h] != B[h]){
                if(A[h] == 'z'){
                    A[h] = 'a';
                    qtd++;
                }else{
                    int aux = A[h];
                    aux += 1;
                    A[h] = aux;
                    qtd++;
                }
            }
        }
        cout << qtd << endl;
    }

    return 0;
}
