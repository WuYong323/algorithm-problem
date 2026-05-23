#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst[110];
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	int dp[10010];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=lst[i];j--){
			dp[j]+=dp[j-lst[i]];
		}
	}
	cout<<dp[m];
	return 0;
}