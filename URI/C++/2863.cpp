#include<iostream>
using namespace std;

int main(){
    int N;
    double menor, num;

    while(cin >> N){
        for(int i=0; i<N; i++){
            cin >> num;
            if(i == 0)
                menor = num;
            else if(menor > num)
                menor = num;
        }
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << menor << endl;
    }

    return 0;
}
