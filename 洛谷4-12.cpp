#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int lst[n];
	int sum[n-m+1];
	for(int i=0;i<n;i++) {
		scanf("%d",&lst[i]);
	}
	for (int i=0;i<n-m+1;i++) {
		sum[i]=0;
	}		
	for (int j=0;j<n-m+1;j++) {
		for (int q=j;q<m+j;q++) {
			sum[j]+=lst[q];
		}
	}
	int t=sum[0];
	for (int p=0;p<n-m;p++) {
		if(t>sum[p+1]) {
			t=sum[p+1];
		}
	}
	printf("%d",t);
	return 0;
}