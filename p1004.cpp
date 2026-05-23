#include<bits/stdc++.h>
#define N 15
using namespace std;

int dp[N][N][N][N];
int a[N][N];
int n,x,y,z;

int main()
{
	cin>>n;
	while(1){
		cin>>x>>y>>z;
		if(x==y&&y==z&&z==0){
			break;
		}
		else{
			a[x][y]=z;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
					if(i==k&&l==j)dp[i][j][k][l]-=a[i][j];
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
	return 0;
}
