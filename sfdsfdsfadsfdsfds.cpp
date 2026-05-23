#include<stdio.h>

int main()
{
	int lst[4][4];
	int t=1;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			lst[i][j]=t;
			t++;
		}
	}
	int p;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=i;++j){
			p=lst[i][j];
			lst[i][j]=lst[j][i];
			lst[j][i]=p;
		}
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			printf("%d ",lst[i][j]);
		}
		printf("\n");
	}
	return 0;
}