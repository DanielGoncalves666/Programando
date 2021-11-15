#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int N;
string conver;
int R,G,B;

int min();
int max();
int mean();
int eye();

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> conver;
		cin >> R >> G >> B;
		if(conver.compare("min") == 0)
			cout << "Caso #" << i + 1 << ": " << min() << endl;
		else if(conver.compare("max") == 0)
			cout << "Caso #" << i + 1 << ": " << max() << endl;
		else if(conver.compare("mean") == 0)
			cout << "Caso #" << i + 1 << ": " << mean() << endl;
		else if(conver.compare("eye") == 0)
			cout << "Caso #" << i + 1 << ": " << eye() << endl;	
	}

	return 0;
}

int min(){
	if(R <= G && R <= B)
		return R;
	if(G <= R && G <= B)
		return G;
	if(B <= R && B <= G)
		return B;
}

int max(){
	if(R >= G && R >= B)
		return R;
	if(G >= R && G >= B)
		return G;
	if(B >= R && B >= G)
		return B;
}

int mean(){
	return floor((R+G+B)/3);
}

int eye(){
	return floor(0.30*R + 0.59*G + 0.11*B);
}
