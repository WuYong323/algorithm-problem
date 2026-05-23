#include<bits/stdc++.h>
#define N 1005
using namespace std;

const int mod=1e9+7;

int n,w;
int a[N];
int dp[10005];

int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i];j<=w;++j){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout<<dp[w]%mod;
	return 0;
}