#include<stdio.h>

int num(int a,int n) 
{
	int t;
	if(a==n) {
		return 1;
	}
	if(a<n) {
		t=(num(a+1,n)+1)*2;
		return t;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",num(1,n));
	return 0;
}