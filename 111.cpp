#include<stdio.h>

int ages(int a){
	if(a==5){
		return 10;
	}
	return ages(a+1)+2;
}

int main()
{
	printf("%d",ages(1));
	return 0;
}