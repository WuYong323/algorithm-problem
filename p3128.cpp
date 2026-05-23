#include<bits/stdc++.h>
#define N 50005
#define M 100005
using namespace std;

int n,k;
vector<int> e[N];
vector<pair<int,int>> query[M];
int vis[N];
int ans[M];
int fa[N];
int dfs_fa[N];
int res[N];
int a[M],b[M];
int maxn;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}

void tarjan(int u,int pa){
	vis[u]=1;
	dfs_fa[u]=pa;
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

void dfs(int u,int pa){
	for(int v:e[u]){
		if(v==pa) continue;
		dfs(v,u);
		res[u]+=res[v];
	}
	maxn=max(maxn,res[u]);
}

int main()
{
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=k;++i){
		cin>>u>>v;
		a[i]=u;
		b[i]=v;
		query[u].push_back({v,i});
		query[v].push_back({u,i});
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	tarjan(1,0);
	for(int i=1;i<=k;++i){
		int u=a[i];
		int v=b[i];
		int lca=ans[i];
		res[u]++;
		res[v]++;
		res[lca]--;
		if(lca!=1) res[dfs_fa[lca]]--;
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}