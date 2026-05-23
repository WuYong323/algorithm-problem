#include<bits/stdc++.h>
using namespace std;

int n,w;
int a[1005];
int dp[10005];

int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=w;++i){
		dp[i]=10005;
	}
	for(int i=1;i<=n;++i){
		for(int j=a[i];j<=w;++j){
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	cout<<dp[w];
	return 0;
}