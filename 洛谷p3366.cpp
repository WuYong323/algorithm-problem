#include<bits/stdc++.h>
#define N 5005
#define inf 0x7f7f7f7f
using namespace std;

struct edge{
	int v,w;
};

vector<edge> e[N];
int n,m;
int d[N],vis[N];
int cnt;
int ans;

bool prime(int s){
	for(int i=0;i<=n;++i) d[i]=inf;
	d[s]=0;
	for(int i=1;i<=n;++i){
		int u=0;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&d[u]>d[j]) u=j;
		}
		vis[u]=1;
		ans+=d[u];
		if(d[u]!=inf) cnt++;
		for(auto ed:e[u]){
			int v=ed.v;
			int w=ed.w;
			if(d[v]>w) d[v]=w;
		}
	}
	return cnt==n;
}

int main()
{
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	if(prime(1)){
		cout<<ans;
	}
	else{
		cout<<"orz";
	}
	return 0;
}