#include<stdio.h>

int main()
{
	long long m,n,num[10];
	scanf("%d %d",&m,&n);
	for (int i=0;i<10;i++) {
		num[i]=0;
	}
	for (long long i=m;i<=n;i++) {
		long long t=i;
		while (t!=0) {
			num[t%10]++;
			t/=10;
		}
	}
	for (int i=0;i<10;i++) {
		printf("%d ",num[i]);
	}
	return 0;
}