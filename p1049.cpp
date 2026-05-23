#include<bits/stdc++.h>
using namespace std;

int v,n;
int vi[35];
int dp[20005];

int main()
{
	cin>>v>>n;
	for(int i=1;i<=n;++i){
		cin>>vi[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=v;j>=vi[i];--j){
			dp[j]=max(dp[j-vi[i]]+vi[i],dp[j]);
		}
	}
	cout<<v-dp[v];
	return 0;
}