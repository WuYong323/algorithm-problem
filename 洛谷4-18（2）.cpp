#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lst[n][n];
	for (int q=0;q<n;q++) {
		for (int p=0;p<n;p++) {
			lst[q][p]=0;
		}
	}
	int num;
	int sum=0;
	int znum=0;
	while (sum<n*n) {
		scanf("%d",&num);
		for (int k=1;k<=num;k++) {
			lst[sum/n][sum%n]=znum;
			sum++;
		}
		znum=1-znum;
	}
	for (int q=0;q<n;q++) {
		for (int p=0;p<n;p++) {
			printf("%d",lst[q][p]);
		}
		printf("\n");
	}
	return 0;
}