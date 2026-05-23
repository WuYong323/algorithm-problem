#include<stdio.h>

double pinjun(int lst[],int m) 
{
	int t=lst[0];
	int s=lst[0];
	int sum=lst[0];
	double score;
	for (int i=1;i<m;i++) {
		if(t<lst[i]) {
			t=lst[i];
		}
		if(s>lst[i]) {
			s=lst[i];
		}
		sum+=lst[i];
	}
	score=(sum-t-s)/1.0/(m-2);
	return score;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int lst[n][m];
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d",&lst[i][j]);
		}
	}
	double lst1[n];
	for (int k=0;k<n;k++) {
		lst1[k]=pinjun(lst[k],m);
	}
	double q=lst1[0];
	for (int l=1;l<n;l++) {
		if(q<lst1[l]) {
			q=lst1[l];
		}
	}
	printf("%.2f",q);
	return 0;
}
