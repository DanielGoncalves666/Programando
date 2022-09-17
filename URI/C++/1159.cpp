#include<iostream>
using namespace std;

int X,i,soma,cont;

int main(){
    for(;;){
        soma=0;
        cont=0;
        cin>>X;
        if(X==0)
            break;
        for(i=X;;i++){
            if(i%2==0){
                soma+=i;
                cont++;
            }
            if(cont==5)
                break;
        }
        cout<<soma<<endl;
    }


    return 0;
}
