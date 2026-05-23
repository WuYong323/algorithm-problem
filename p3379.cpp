#include<bits/stdc++.h>
#define N 500005
#define M 500005
using namespace std;

int n,m,s;
vector<int> e[N];
vector<pair<int,int>> query[N];
int fa[N],vis[N],ans[M];

int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}

void tarjan(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(!vis[v]){
			tarjan(v);
			fa[v]=u;
		}
	}
	for(auto q:query[u]){
		int v=q.first;
		int i=q.second;
		if(vis[v]) ans[i]=find(v);
	}
}

int main()
{
	cin>>n>>m>>s;
	int a,b;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		query[a].push_back({b,i});
		query[b].push_back({a,i});
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	tarjan(s);
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}