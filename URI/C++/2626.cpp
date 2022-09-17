#include<iostream>
#include<string>
using namespace std;

string str1, str2, str3;
int dodo, leo, pepper, soma;

void determinarValor(string str, int *nome);
void imprimir(int num);

int main(){
	while(cin >> str1 && cin >> str2 && cin >> str3){
		soma = 0;
		determinarValor(str1,&dodo);
		determinarValor(str2,&leo);
		determinarValor(str3,&pepper);
		
		if(soma == 3 || soma == 5 || soma == 6 || soma == 8 || soma == 9)
			cout << "Putz vei, o Leo ta demorando muito pra jogar...\n";
		if(soma == 4 && dodo == 2)
			imprimir(1);
		else if(soma == 4 && leo == 2)
			imprimir(2);
		else if(soma == 4 && pepper == 2)
			imprimir(3);
			
		if(soma == 7){
			if(dodo == 1)
				imprimir(1);
			else if(leo == 1)
				imprimir(2);
			else if(pepper == 1)
				imprimir(3);
			else if(dodo == 3)
				imprimir(1);
			else if(leo == 3)
				imprimir(2);
			else if(pepper == 3)
				imprimir(3);
		}
	}

	return 0;
}

void determinarValor(string str, int *nome){
	if(str.compare("papel") == 0)
		*nome = 1;
	else if(str.compare("tesoura") == 0)
		*nome = 2;
	else if(str.compare("pedra") == 0)
		*nome = 3;
	
	soma += *nome;
}

void imprimir(int num){
	if(num == 1)
		cout << "Os atributos dos monstros vao ser inteligencia, sabedoria...\n";
	if(num == 2)
		cout << "Iron Maiden's gonna get you, no matter how far!\n";
	if(num == 3)
		cout << "Urano perdeu algo muito precioso...\n";
}

/*
Empate	soma
1 1 1   3
2 2 2   6
1 2 3   6
3 3 3   9
1 2 2   5 empate
1 1 3   5 empate
2 3 3   8 empate

1 1 2   4 tesoura
1 3 3   7 papel
2 2 3   7 pedra

1 - papel
2 - tesoura
3 - pedra
*/

