#include<stdio.h>

int main()
{
	int n,minute1,minute2;
	scanf("%d",&n);
	minute1=5*n;
	minute2=11+3*n;
	if (minute1>minute2) {
		printf("Luogu");
	}
	else {
		printf("Local");
	}
	return 0;
}