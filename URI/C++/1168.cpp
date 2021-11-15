#include<iostream>
#include<string>
using namespace std;

int main(){
	int N, vet[] = {6,2,5,5,4,5,6,3,7,6};
	string num;

	cin >> N;
	for(int i=0; i<N; i++){
		int qtd = 0;
		cin >> num;

		for(int h=0; h<num.size(); h++){
			qtd+= vet[num[h] - '0'];
		}
		cout << qtd << " leds\n";
	}
	return 0;
}