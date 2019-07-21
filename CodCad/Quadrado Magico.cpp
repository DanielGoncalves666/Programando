#include<iostream>
using namespace std;

    int N,i,h,soma=0,somaux,resul=0,colusom,diagonal=0;

int main(){
    cin>>N;
    int mat[N][N];
    for(i=0;i<N;i++){
        somaux=0;
        for(h=0;h<N;h++){
            cin>>mat[i][h];
            if(i==0)
                soma+=mat[0][h];
            else
                somaux+=mat[i][h];
            if(i==h)
                diagonal+=mat[i][h];
        }
        if(somaux!=soma && i!=0)
            resul=-1;
    }
    if(diagonal!=soma)
        resul=-1;

    diagonal=0;
    for(h=0;h<N;h++){
        colusom=0;
        for(i=0;i<N;i++){
            colusom+=mat[i][h];
            if(N-1*i-1==h)
                diagonal+=mat[i][h];
        }
        if(colusom!=soma)
            resul=-1;
    }
    if(diagonal!=soma)
        resul=-1;

    if(resul==-1)
        cout<<resul<<endl;
    else
        cout<<soma<<endl;

    return 0;
}
