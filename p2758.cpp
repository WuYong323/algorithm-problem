#include<bits/stdc++.h>
#define N 2005
using namespace std;

string a,b;
int dp[N][N];

int main()
{
	cin>>a>>b;
	int m=a.length(),n=b.length();
	for(int i=0;i<=m;++i) dp[i][0]=i;
	for(int j=0;j<=n;++j) dp[0][j]=j;
	
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
			}
		}
	}
	cout<<dp[m][n];
	return 0;
}