#include<bits/stdc++.h>
#define N 105
#define ll long long
using namespace std;

int n,k;
ll a[N][N],dp[N][N][5505],ans=-3e9;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			for(int l=0;l<=k;++l){
				dp[i][j][l]=-3e9;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			cin>>a[i][j];
			for(int l=0;l<=k&&l<=i;++l){
				if(l==0){
					dp[i][j][l]=max(dp[i-1][j][l],dp[i-1][j-1][l])+a[i][j];
				}
				else{
					dp[i][j][l]=max(dp[i-1][j][l],dp[i-1][j-1][l])+a[i][j];
					dp[i][j][l]=max(dp[i][j][l], max(dp[i-1][j][l-1],dp[i-1][j-1][l-1])+a[i][j]*3);
				}
			}
		}
	}
	k=min(k,n);
	for(int j=1;j<=n;++j){
		for(int l=0;l<=k;++l){
			ans=max(ans,dp[n][j][l]);
		}
	}
	cout<<ans;
	return 0;
}
