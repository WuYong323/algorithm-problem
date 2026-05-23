#include<stdio.h>

int main()
{
	double s;
	scanf("%lf",&s);
	double sum=0;
	int i=0;
	double k=2;
	while (sum<s) {
		i++;
		sum+=k;
		k*=0.98;
	}
	printf("%d",i);
	return 0;
}