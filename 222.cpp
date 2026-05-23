#include<stdio.h>

void fun(int n,char a,char b,char c){
	if(n==1){
		printf("move %d from %c to %c\n",n,a,c);
		return;
	}
	fun(n-1,a,c,b);
	printf("move %d from %c to %c\n",n,a,c);
	fun(n-1,b,a,c);
}

int main()
{
	fun(3,'a','b','c');
	return 0;
}