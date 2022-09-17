#include<iostream>
using namespace std;

int main(){
	string chave, frase, vogais = "aeiou";
	int qtd;

	cin >> chave;
	cin >> qtd;
	getline(cin,frase);

	for(int i=0; i<qtd; i++){
		getline(cin, frase);

		int aux;
		for(int h=0, j=0; h<frase.size(); h++){
			if(frase[h] == ' ')
				continue;
			
			if(h == 0){
				if(vogais.find(frase[h]) != string::npos){//se a primeira letra for uma vogal
					h = frase.find(' ',h);//procura o proximo espaço

					if(h == string::npos)
						break;//se n houver nenhuma outra palavra
					else
						continue;//se houver, continua e o laço vai começar na primeira letra já
				}
			}else if(frase[h-1] == ' '){
				if(vogais.find(frase[h]) != string::npos){//se a primeira letra for uma vogal
					h = frase.find(' ',h);//procura o proximo espaço

					if(h == string::npos)
						break;//se n houver nenhuma outra palavra
					else
						continue;//se houver, continua e o laço vai começar na primeira letra já
				}
			}
			
			aux = (int) frase[h] - (int) 'a';//valor entre 0 e 25. 0 = 'a' e 25 = 'z'
			aux += (int) chave[j] - (int) 'a';//vai deslocar o valor entre 0 e 25 à direita

			if(aux > 25)
				aux -= 26;//a qtd de letras no alfabeto

			frase[h] = (char) (aux + (int) 'a');

			if(j == chave.size() - 1)
				j = 0;
			else
				j++;
		}
		cout << frase << "\n";
	}

	return 0;
}