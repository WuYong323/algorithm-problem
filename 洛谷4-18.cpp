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
	int num_0,num_1;
	int sum=0;
	while (sum<n*n) {
		scanf("%d",&num_0);
		scanf("%d",&num_1);
		for (int k=1;k<=num_0;k++) {
			lst[sum/n][sum%n]=0;
			sum++;
		}
		for (int l=1;l<=num_1;l++) {
			lst[sum/n][sum%n]=1;
			sum++;
		}
	}
	for (int q=0;q<n;q++) {
		for (int p=0;p<n;p++) {
			printf("%d",lst[q][p]);
		}
		printf("\n");
	}
	return 0;
}