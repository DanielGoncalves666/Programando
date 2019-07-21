#include<iostream>
using namespace std;

float a,soma,media;
int i,b;

int main(){
    for(;;){
        soma=0.0;
        for(i=0;i<2;){
            cin>>a;
            if(a<0.0 || a>10.0)
                cout<<"nota invalida"<<endl;
            else{
                soma+=a;
                i++;
            }
        }
        media=soma/2;
        cout.precision(2);
        cout.setf(ios::fixed);
        cout<<"media = "<<media<<endl;
        for(;;){
            cout<<"novo calculo (1-sim 2-nao)"<<endl;
            cin>>b;
            if(b<1 || b>2)
                continue;
            else
                break;
        }
        if(b==2)
            break;
    }

    return 0;
}
