#include<bits/stdc++.h>
using namespace std;

int dp[25];
int n;
int num[25];
bool net[25][25];
int p[25];
int pos=1;
int ans;

void dfs(int x){
	if(p[x]) dfs(p[x]);
	cout<<x<<" ";
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>num[i];
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			cin>>net[i][j];
		}
	}
	dp[1]=num[1];
	ans=num[1];
	for(int i=2;i<=n;++i){
		dp[i]=num[i];
		for(int j=i-1;j>=1;--j){
			if(net[j][i]&&dp[i]<dp[j]+num[i]){
				dp[i]=dp[j]+num[i];
				p[i]=j;
			}
		}
		if(ans<dp[i]){
			ans=dp[i];
			pos=i;
		}
	}
	dfs(pos);
	cout<<endl<<ans;
	return 0;
}