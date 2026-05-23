#include<stdio.h>

int main()
{
	char word;
	int a;
	word=getchar();
	a=(int) word;
	printf("%c", a-32);
	return 0;
}