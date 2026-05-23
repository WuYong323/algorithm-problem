#include<stdio.h>

int lst[15][15];
int main()
{
	lst[1][1]=1;
	lst[2][1]=1;
	lst[2][2]=1;
	for(int i=3;i<=10;i++){
		for(int j=1;j<=i;j++){
			lst[i][j]=lst[i-1][j]+lst[i-1][j-1];
		}
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=i;j++){
			printf("%d ",lst[i][j]);
		}
		printf("\n");
	}
	return 0;
}