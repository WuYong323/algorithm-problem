#include<stdio.h>

int main()
{
	int n,a,n1;
	scanf("%d",&n);
	char score[n];
	for (int i=1;i<=n;i++) {
		scanf("%d",&a);
		score[i]=a;
		for (int j=1;j<=i;j++) {
			if (score[i]>score[j]) {
				n1++;
			}
		}
		printf("%d ",n1);
		n1=0;
	}
	return 0;
}