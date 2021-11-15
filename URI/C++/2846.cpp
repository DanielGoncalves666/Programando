#include<iostream>
using namespace std;

void fibonacci(int *num1, int *num2);

int main(){
	int N, anterior1 = 5, anterior2 = 3;//começamos por f4 e f3 pois o primeiro fibonot é 4

	cin >> N;

	int qtd = 0;
	for(int i=4;;i++){
		if(i == anterior1){
			fibonacci(&anterior1,&anterior2);
			continue;
		}else
			qtd++;

		if(N == qtd){
			cout << i << endl;
			break;
		}
	}


	return 0;
}

void fibonacci(int *num1, int *num2){
	int prox = *num1 + *num2;
	*num2 = *num1;
	*num1 = prox;
}