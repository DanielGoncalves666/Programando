#include<iostream>
using namespace std;

    int h,p,f,d;

int main(){
    cin>>h>>p>>f>>d;
    if(f>h){
        if(f<p or h>p){
            if(d==-1)
                cout<<"S\n";
            else
                cout<<"N\n";
        }
        if(p<f and p>h){
            if(d==-1)
                cout<<"N\n";
            else
                cout<<"S\n";
        }
    }
    if(f<h){
        if(p>h or p<f){
            if(d==-1)
                cout<<"N\n";
            else
                cout<<"S\n";
        }
        if(p<h and p>f){
            if(d==-1)
                cout<<"S\n";
            else
                cout<<"N\n";
        }
    }
    return 0;
}
