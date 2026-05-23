#include<stdio.h>

long long fb(int n)
{
	if(n==0) {
		return 0;
	}
	if(n==1 || n==2){
		return 1;
	}
	long long a=0,b=1,c;
	for (int i=2;i<=n;i++) {
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%.2f",fb(n)/1.0);
	return 0;
}