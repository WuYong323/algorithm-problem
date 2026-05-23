#include<stdio.h>
#include<math.h>

int main()
{
	int sum=0;
	int z;
	int p=0;
	while (scanf("%d",&z)!=EOF) {
		sum+=z;
		p++;
	}
	long long q=pow(2,p-1);
	printf("%lld",sum*q);
	return 0;
}