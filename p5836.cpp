#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m;
vector<int> e[N];
vector<pair<int,int>> query[N];
int fa[N],dfs_fa[N],vis[N],ans[N];
char name[N];
int u[N],v[N];
char node[N];
int cnt[N][2];

int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}

void tarjan(int u,int f){
	dfs_fa[u]=f;
	vis[u]=1;
	if(node[u]=='G') cnt[u][0];
	if(node[u]=='H') cnt[u][1]++;
	for(int v:e[u]){
		if(!vis[v]){
			tarjan(v,u);
			fa[v]=u;
		}
	}
	for(auto q:query[u]){
		int v=q.first;
		int i=q.second;
		if(vis[v]) ans[i]=find(v);
	}
}

bool check(int u,int lca,char tar){
	while(1){
		if(u==lca) break;
		if(node[u]==tar) return true;
		u=dfs_fa[u];
	}
	if(node[lca]==tar) return true;
	return false;
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=n;++i) cin>>node[i];
	for(int i=1;i<n;++i){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>name[i];
		query[u[i]].push_back({v[i],i});
		query[v[i]].push_back({u[i],i});
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	tarjan(1,0);
	for(int i=1;i<=m;++i){
		int lca=ans[i];
		if(check(u[i],lca,name[i])||check(v[i],lca,name[i])){
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}