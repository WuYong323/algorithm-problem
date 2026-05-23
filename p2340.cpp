#include<bits/stdc++.h>
#define pian 400000
#define inf 0x3f3f3f3f
using namespace std;

int n;
int s[405],f[405];
int dp[800005];
int ans;

int main()
{
	cin>>n;
	fill(dp,dp+800005,-inf);
	dp[pian]=0;
	for(int i=1;i<=n;++i){
		cin>>s[i]>>f[i];
	}
	for(int i=1;i<=n;++i){
		if(s[i]>=0){
			for(int j=800000-s[i];j>=0;--j){
				if(dp[j]!=-inf){
					dp[j+s[i]]=max(dp[j+s[i]],dp[j]+f[i]);
				}
			}
		}
		else{
			for(int j=-s[i];j<=800000;++j){
				if(dp[j]!=-inf){
					dp[j+s[i]]=max(dp[j+s[i]],dp[j]+f[i]);
				}
			}
		}
	}
	for(int i=pian;i<=800000;++i){
		if(dp[i]>=0){
			ans=max(ans,(i-pian)+dp[i]);
		}
	}
	cout<<ans;
	return 0;
}