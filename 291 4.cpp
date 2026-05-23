#include<stdio.h>

void solve(int *lst,int n,int m){
	for(int i=1;i<=m;++i){
		int temp=lst[n];
		for(int j=n;j>=2;--j){
			lst[j]=lst[j-1];
		}
		lst[1]=temp;
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int lst[n+5];
	for(int i=1;i<=n;++i){
		scanf("%d",&lst[i]);
	}
	solve(lst,n,m);
	for(int i=1;i<=n;++i){
		printf("%d ",lst[i]);
	}
	return 0;
}