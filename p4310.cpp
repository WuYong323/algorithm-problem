#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int dp[100005];
int bit[32];
int ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int best=0;
		for(int k=0;k<31;++k){
			if((a[i]>>k)&1) best=max(best,bit[k]);
		}
		dp[i]=best+1;
		for(int k=0;k<31;++k){
			if((a[i]>>k)&1) bit[k]=max(bit[k],dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}