#include<stdio.h>

int main()
{
	int n;
	long long t,mul;
	double a;
	printf("asd");
	scanf("%d",&n);
	int num[2000000]={0};
	for (int i=1;i<=n;i++) {
		scanf("%lf %d",&a,&t);
		for (int j=1;j<=t;j++) {
			mul=(int)a*j;
			num[mul-1]++;
		}
	}
	for (int p=0;p<2000000;p++) {
		if(num[p]%2!=0) {
			printf("%d",p+1);
		}
	}
	return 0;
}