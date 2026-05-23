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
	for(int i=1;i<=w;++i){
		for(int j=1;j<=n;++j){
			if(i-a[j]>=0){
				dp[i]=(dp[i]+dp[i-a[j]])%mod;
			}
		}
	}
	cout<<dp[w]%mod;
	return 0;
}