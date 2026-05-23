#include<stdio.h>

int main()
{
	int n,s;
	int p=0;
	int q=10;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&s);
		if (s>=p) {
			p=s;
		}
		if (s<=q) {
			q=s;
		}
		sum+=s;
	}
	printf("%.2f",(sum-p-q)/(n-2.0));
	return 0;
}