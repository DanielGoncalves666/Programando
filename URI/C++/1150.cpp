#include<iostream>
using namespace std;

int X,Y,cont,i,soma;

int main(){
    cin>>X;
    for(;;){
        cin>>Y;
        if(Y>X)
            break;
    }
    soma=0;
    for(i=X;;i++){
        soma+=i;
        cont++;
        if(soma>Y)
            break;
    }
    cout<<cont<<endl;
    return 0;
}
