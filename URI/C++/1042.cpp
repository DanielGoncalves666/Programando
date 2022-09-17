#include<iostream>
using namespace std;

int vet[3],vet_a[3], i, a;

int main(){
	for(i=0;i<3;i++){
		cin>>vet[i];
		vet_a[i]=vet[i];
	}
	for(;;){
		if(vet_a[1]>vet_a[2]){
			a=vet_a[1];
			vet_a[1]=vet_a[2];
			vet_a[2]=a;
		}else if(vet_a[0]>vet_a[1]){
			a=vet_a[0];
			vet_a[0]=vet_a[1];
			vet_a[1]=a;
		}else
			break;
	}
	for(i=0;i<3;i++){
		cout<<vet_a[i]<<endl;
	}
	cout<<endl;
	for(i=0;i<3;i++){
		cout<<vet[i]<<endl;
	}
	return 0;
}
