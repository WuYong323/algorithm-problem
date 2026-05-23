#include<stdio.h>

int main()
{
	char lst1[15][15];
	for (int i=1;i<=5;i++) {
		for (int j=1;j<=5;j++)
			scanf("%c",&lst1[i][j]);
			getchar();
	}
	for (int i=1;i<=5;i++) {
		for (int j=1;j<=5;j++) {
			printf("%c",&lst1[i][j]);
		}
		printf("\n");
	}
	return 0;
}