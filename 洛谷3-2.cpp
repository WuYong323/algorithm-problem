#include<stdio.h>

int main()
{
	int n,k;
	int k1=0;
	int k2=0;
	int a=0;
	int b=0;
	double result1,result2;
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++) {
		if(i%k==0) {
			k1+=i;
			a++;
		}
		else {
			k2+=i;
			b++;
		}
	}
	result1=(double)k1/a;
	result2=(double)k2/b;
	printf("%.1f %.1f",result1,result2);
	return 0;
}