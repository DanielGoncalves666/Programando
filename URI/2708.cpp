#include<iostream>
#include<string>
using namespace std;

int main(){
    int T,turistas = 0, jipes = 0;
    string str;
    for(;;){
        cin >> str;
        if(str.compare("ABEND") == 0)
          break;

        cin >> T;

        if(str.compare("SALIDA") == 0){
            jipes++;
            turistas += T;
        }
        if(str.compare("VUELTA") == 0){
            jipes--;
            turistas -= T;
        }
    }
    cout << turistas << endl << jipes << endl;

    return 0;
}
