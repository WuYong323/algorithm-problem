#include<stdio.h>

void hano(int n,char a,char b,char c){
	if(n==1){
		printf("move %d from %c to %c\n",n,a,c);
		return;
	}
	hano(n-1,a,c,b);
	printf("move %d from %c to %c\n",n,a,c);
	hano(n-1,b,a,c);
}


int main()
{
	hano(3,'a','b','c');
	return 0;
}