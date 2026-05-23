#include<stdio.h>

int jiecheng(int n)
{
	if(n==1) {
		return 1;
	}
	if(n==2) {
		return 2;
	}
	if (n>2) {
		return n*jiecheng(n-1);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",jiecheng(n));
	return 0;
}