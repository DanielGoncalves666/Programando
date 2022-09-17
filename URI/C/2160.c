#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[502];

int main(){
	fgets(str,502,stdin);
	if(strlen(str)-1 > 80)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
