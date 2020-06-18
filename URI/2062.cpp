#include<iostream>
#include<string>
using namespace std;

int N;
string str;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        if(str.size() == 3 && (str.compare(0,2,"OB") == 0 || str.compare(0,2,"UR") == 0)){
            str[2] = 'I';
        }
        cout << str;

        if(i < N-1)
            cout << " ";
    }
    cout << endl;


    return 0;
}
