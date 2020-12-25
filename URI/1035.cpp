#include<iostream>
using namespace std;

int main(){
	int a,b,c,d;

	cin >> a >> b >> c >> d;

	do{
		if(a % 2 == 1){// se for impar
			cout << "Valores nao aceitos" << endl;
			break;
		}

		if(c <= 0 || d <= 0){//se eles n forem positivos
			cout << "Valores nao aceitos" << endl;
			break;
		}

		if(c + d <= a + b){//se a soma dos primeiros n for mairo que dos ultimos
			cout << "Valores nao aceitos" << endl;
			break;
		}

		if(b <= c || d <= a){
			cout << "Valores nao aceitos" << endl;
			break;
		}

		cout << "Valores aceitos" << endl;
	}while(false);


	return 0;
}