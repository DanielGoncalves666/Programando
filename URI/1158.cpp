#include<iostream>
using namespace std;

int i,N,X,Y,h,cont,soma;

int main(){
    for(i=0;i<N;i++){
        soma=0;
        cont=0;
        cin>>X>>Y;
        for(h=X;;h++){
            if(h%2==1){
                soma+=h;
                cont++;
            }
            if(cont==Y)
                break;
        }
        cout<<soma<<endl;
    }

    return 0;
}
