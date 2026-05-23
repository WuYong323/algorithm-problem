#include<bits/stdc++.h>
#define N 1000005
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

int n,m,q;
vector<pair<int,int>> g[N];
ll dp[N][30];

int main()
{
	cin>>n>>m>>q;
	while(m--){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		g[u].emplace_back(v,w);
	}
	for(int i=1;i<=n;++i){
		dp[i][0]=1;
	}
	for(int i=1;i<=30;++i){
		for(int j=1;j<=n;++j){
			for(auto [v,w]:g[j]){
				dp[j][i]=max(dp[j][i],min(dp[v][i-1]*w,inf*1ll));
			}
		}
	}
	while(q--){
		int p,x;
		cin>>p>>x;
		for(int i=1;i<=30;++i){
			if(dp[p][i]>x){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}