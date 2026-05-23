#include<bits/stdc++.h>
#define N 355
#define M 125
using namespace std;

int n,m;
int a[N],b;
int cnt[5];
int dp[43][43][43][43];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>b;
		cnt[b]++;
	}
	dp[0][0][0][0]=a[1];
	for(int i=0;i<=cnt[1];++i){
		for(int j=0;j<=cnt[2];++j){
			for(int k=0;k<=cnt[3];++k){
				for(int l=0;l<=cnt[4];++l){
					if(i==0&&j==0&&k==0&&l==0) continue;
					int pos=1+i*1+j*2+3*k+4*l;
					int best=0;
					if(i>0)best=max(best,dp[i-1][j][k][l]);
                	if(j>0)best=max(best,dp[i][j-1][k][l]);
                	if(k>0)best=max(best,dp[i][j][k-1][l]);
                	if(l>0)best=max(best,dp[i][j][k][l-1]);
					dp[i][j][k][l]=best+a[pos];
				}
			}
		}
	}
	cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	return 0;
}