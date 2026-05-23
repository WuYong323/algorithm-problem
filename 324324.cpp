#include<stdio.h>

void digui(int n,char a,char b,char c){
	if(n==1){
		printf("move %d from %c to %c\n",n,a,c);
		return;
	}
	digui(n-1,a,c,b);
	printf("move %d from %c to %c\n",n,a,c);
	digui(n-1,b,a,c);
}

int main()
{
	digui(4,'a','b','c');
	return 0;
}