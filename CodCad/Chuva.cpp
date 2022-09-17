#include<iostream>
using namespace std;

    int N,i,h;

int main(){
    cin>>N;

    int mat[2*N][N];

    for(i=0;i<2*N;i++){
        for(h=0;h<N;h++){
            cin>>mat[i][h];
        }
    }

    for(i=0;i<N;i++){
        for(h=0;h<N;h++){
            cout<<mat[i][h]+mat[i+N][h]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
