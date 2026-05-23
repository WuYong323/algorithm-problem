#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lst[n][n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			lst[i][j]=0;
		}
	}
	int i=0;
	int j=(n-1)/2;
	lst[i][j]=1;
	for (int k=1;k<=n*n;k++) {
		if(i==0 && j!=n-1) {
			i=n-1;
			j=j+1;
			lst[i][j]=k+1;
		}
		else if (i!=0 && j==n-1) {
			i=i-1;
			j=0;
			lst[i][j]=k+1;
		}
		else if (i==0 && j==n-1) {
			i=i+1;
			lst[i][j]=k+1;
		}
		else if (i!=0 && j!=n-1) {
			if (lst[i-1][j+1]==0) {
				i=i-1;
				j=j+1;
				lst[i][j]=k+1;
			}
			else {
				i=i+1;
				lst[i][j]=k+1;
			}
		}
	}
	for (int p=0;p<n;p++) {
		for(int q=0;q<n;q++) {
			printf("%d ",lst[p][q]);
		}
		printf("\n");
	}
	return 0;
}