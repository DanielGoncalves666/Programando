#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main()
{
	string str;

	while(getline(cin, str)){
		int qtd = 0, invalido=0, total = 0, qtdWords = 0;
		for(int i=0; i < str.size(); i++)
		{

			if(str[i] == ' ')
			{
				if((invalido == 0 || (invalido == 1 && str[i-1] == '.')) && qtd > 0)
				{
					total += qtd;
					qtdWords++;
				}
				qtd = 0;
				invalido = 0;
			}
			else if(i == str.size() - 1)
			{
				if(str[i] != ' '){
					if(isalpha(str[i]))
						qtd++;
					else if(isalpha(str[i]) == 0)
						invalido++;
				}

				if((invalido == 0 || (invalido == 1 && str[i] == '.')) && qtd > 0)
				{
					total += qtd;
					qtdWords++;
				}
				qtd = 0;
				invalido = 0;
			}
			else if(isalpha(str[i]))
				qtd++;
			else if(isalpha(str[i]) == 0)
				invalido++;
		}

		double comprimento;

		if(qtdWords == 0)
			comprimento = 0;
		else
			comprimento = total / qtdWords;

		if(comprimento <= 3)
			cout << "250\n";
		else if(comprimento == 4 || comprimento == 5)
			cout << "500\n";
		else if(comprimento >= 6)
			cout << "1000\n";
		
	}

	return 0;
}