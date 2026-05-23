#include<stdio.h>

int lst[20][20];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			lst[i][j]=0;
		}
	}
	int j=1;
	int i=1;
	lst[1][1]=1;
	for (int z=2;z<=n*n;) {
		while (j+1<=n && lst[i][j+1]==0){
			j++;
			lst[i][j]=z;
			z++;
		}
		while(i+1<=n && lst[i+1][j]==0) {
			i++;
			lst[i][j]=z;
			z++;
		}
		while (j-1>=1 && lst[i][j-1]==0){
			j--;
			lst[i][j]=z;
			z++;
		}
		while (i-1>=1 && lst[i-1][j]==0) {
			i--;
			lst[i][j]=z;
			z++;
		}
	}
	
	for (int m=1;m<=n;m++) {
		for (int l=1;l<=n;l++) {
			printf("%3d",lst[m][l]);	
		}
		printf("\n");
	}
	return 0;
}