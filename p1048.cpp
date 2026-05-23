#include<bits/stdc++.h>
using namespace std;

int t,m;
int a[105],b[105];
int dp[1005];

int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;++i){
		cin>>a[i]>>b[i];
	}
	
	for(int i=1;i<=m;++i){
		for(int j=t;j>=a[i];--j){
			dp[j]=max(dp[j-a[i]]+b[i],dp[j]);
		}
	}
	cout<<dp[t];
	return 0;
}