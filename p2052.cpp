#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

struct edge{
	int v,w;
};

vector<edge> e[N];
int u,v,w;
int n;
int ans;
int res;

int dfs(int fa,int u,int pri){
	int sum=1;
	for(auto t:e[u]){
		int v=t.v;
		int w=t.w;
		if(v==fa) continue;
		sum+=dfs(u,v,w);
	}
	ans+=abs(n-sum-sum)*pri;
	return sum;
}

signed main()
{
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}