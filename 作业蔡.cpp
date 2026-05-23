#include<stdio.h>

int main()
{
	int i=1;
	long long sum=0;
	long long mul=1;
	do {
		long long mul=1;
		int t=1;
		while (t<=i) {
			mul*=t;
			t++;
		}
		sum+=mul;
		i++;
	}while (i<=20);
	printf("%lld",sum);
	return 0;
}