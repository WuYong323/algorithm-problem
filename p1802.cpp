#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	int lose;
	int win;
	int use;
}nd[1005];

int x,n;
ll dp[1005];
ll ans;

int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>nd[i].lose>>nd[i].win>>nd[i].use;
		dp[0]+=nd[i].lose;
	}
	for(int i=1;i<=n;++i){
		for(int j=x;j>=nd[i].use;--j){
			dp[j]=max(dp[j-nd[i].use]-nd[i].lose+nd[i].win,dp[j]);
		}
	}
	for(int i=0;i<=x;++i){
		ans=max(ans,dp[i]);
	}
	cout<<5*ans;
	return 0;
}