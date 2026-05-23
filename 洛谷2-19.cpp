#include<stdio.h>

int jiec(int a);

int jiec(int a) {
	int k;
	long long j=1;
	for (k=1;k<=a;k++) {
		j*=k;
	}
	return j;
}

int main()
{
	int n;
	long long p;
	long long s=0;
	scanf("%d",&n);
	for (p=1;p<=n;p++) {
		s+=jiec(p);
	}
	printf("%lld",s);
	return 0;
}