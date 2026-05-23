#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t,m;
int ft[10005],fw[10005];
ll dp[10000005];

int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;++i){
		cin>>ft[i]>>fw[i];
	}
	for(int i=1;i<=m;++i){
		for(int j=ft[i];j<=t;++j){
			dp[j]=max(dp[j],dp[j-ft[i]]+fw[i]);
		}
	}
	cout<<dp[t];
	return 0;
}