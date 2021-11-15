#include<iostream>
#include<cmath>
using namespace std;

void organizar(long long *a, long long *b, long long *c);

int main(){
	long long a, b, c;

	cin >> a >> b >> c;

	if(a >= b + c || b >= a + c || c >= a + b){
		cout << "Invalido" << endl;
	}else if(a <= abs(b-c) || b <= abs(a-c) || c <= abs(a-b)){
		cout << "Invalido" << endl;
	}else{
		if(a == b && b == c){
			cout << "Valido-Equilatero" << endl;
			cout << "Retangulo: N" << endl;
		}else{
			if(a == b || a == c || b == c){
				cout << "Valido-Isoceles" << endl;
			}else{
				cout << "Valido-Escaleno" << endl;
			}

			organizar(&a,&b,&c);

			if((long long) a * a + (long long) b * b == (long long) c * c){
				cout << "Retangulo: S" << endl;
			}else{
				cout << "Retangulo: N" << endl;
			}
		}
	}
	return 0;
}

void organizar(long long *a, long long *b, long long *c){
	if(*a > *b && *a > *c){
		int aux = *a;
		*a = *c;
		*c = aux;
	}else if(*b > *a && *b > *c){
		int aux = *b;
		*b = *c;
		*c = aux;
	}
}