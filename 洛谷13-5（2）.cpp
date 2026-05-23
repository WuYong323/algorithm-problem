#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin>>n;
	vector<pair<double,double>> points(n+1);
	points[0]={0,0};
	for(int i=1;i<=n;i++){
		cin>>points[i].first>>points[i].second;
	}
	vector<vector<double>> dist(n+1,vector<double>(n+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			double xx=points[i].first-points[j].first;
			double yy=points[i].second-points[j].second;
			dist[i][j]=sqrt(xx*xx+yy*yy);
		}
	}
	int all=1<<(n+1);
	vector<vector<double>> dp(all,vector<double>(n+1,1e18));
	dp[1][0]=0;
	for(int mark=1;mark<all;mark++){
		for(int i=0;i<=n;i++){
			if(dp[mark][i]>=1e18){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(mark>>j&1){
					continue;
				}
				int newmark=mark|(1<<j);
				dp[newmark][j]=min(dp[newmark][j],dp[mark][i]+dist[i][j]);
			}
		}
	}
	double ans=1e18;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[(1<<(n+1))-1][i]);
	}
	printf("%.2f",ans);
	return 0;
}