#include<stdio.h>

int main()
{
	int n,j,i,k;
	scanf("%d",&n);
	for (j=1;j<=n;j++) {
		for(i=1;i<=n+1-j;i++) {
			k++;
			printf("%02d",k);
		}
		printf("\n");
	}
	return 0;
}