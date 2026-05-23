#include<stdio.h>

int re(int n)
{
	int reverse=0;
	while (n>0) {
		reverse=reverse*10+n%10;
		n/=10;
	}
	return reverse;
}

int main()
{
	int n,fn;
	scanf("%d",&n);
	if(n>0) {
		printf("%d",re(n));
	}
	else if(n==0) {
		printf("0");
	}
	else{
		fn=-n;
		printf("-%d",re(fn));
	}
	return 0;
}