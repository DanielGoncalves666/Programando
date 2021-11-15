#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	int N;
	string str, result;
	
	cin >> N;
	getline(cin,str);

	for(int i=0; i<N; i++){
		result.clear();
		str.clear();

		getline(cin,str);

		for(int i=0; i<str.size(); i++){
			if(str[i] == ' ' || isalpha(str[i]) == 0)
				continue;

			if(str[i] == 'G' || str[i] == 'Q' || str[i] == 'a' || str[i] == 'k' || str[i] == 'u')
				result.append("0");
			else if(str[i] == 'I' || str[i] == 'S' || str[i] == 'b' || str[i] == 'l' || str[i] == 'v')
				result.append("1");
			else if(str[i] == 'E' || str[i] == 'O' || str[i] == 'Y' || str[i] == 'c' || str[i] == 'm' || str[i] == 'w')
				result.append("2");
			else if(str[i] == 'F' || str[i] == 'P' || str[i] == 'Z' || str[i] == 'd' || str[i] == 'n' || str[i] == 'x')
				result.append("3");
			else if(str[i] == 'J' || str[i] == 'T' || str[i] == 'e' || str[i] == 'o' || str[i] == 'y')
				result.append("4");
			else if(str[i] == 'D' || str[i] == 'N' || str[i] == 'X' || str[i] == 'f' || str[i] == 'p' || str[i] == 'z')
				result.append("5");
			else if(str[i] == 'A' || str[i] == 'K' || str[i] == 'U' || str[i] == 'g' || str[i] == 'q')
				result.append("6");
			else if(str[i] == 'C' || str[i] == 'M' || str[i] == 'W' || str[i] == 'h' || str[i] == 'r')
				result.append("7");
			else if(str[i] == 'B' || str[i] == 'L' || str[i] == 'V' || str[i] == 'i' || str[i] == 's')
				result.append("8");		
			else if(str[i] == 'H' || str[i] == 'R' || str[i] == 'j' || str[i] == 't')
				result.append("9");

			if(result.size() == 12)
				break;
		}
		
		cout << result << endl;
	}

	return 0;
}