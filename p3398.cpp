#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,q;
int u,v;
int a,b,c,d;
vector<int> e[N];
int fa[N],dep[N],son[N],sz[N];
int top[N];

void dfs1(int u,int father){
	fa[u]=father;
	dep[u]=dep[father]+1;
	sz[u]=1;
	for(int v:e[u]){
		if(v==father) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

void dfs2(int u,int t){
	top[u]=t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int v:e[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}

int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

bool onpath(int p,int u,int v){
	int x=lca(u,v);
	return(lca(u,p)==p&&lca(p,v)==x||lca(v,p)==p&&lca(p,u)==x);
}

int main()
{
	cin>>n>>q;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=q;++i){
		cin>>a>>b>>c>>d;
		int x=lca(a,b);
		int y=lca(c,d);
		if(onpath(x,c,d)||onpath(y,a,b)){
			cout<<"Y"<<endl;
		}
		else cout<<"N"<<endl;
	}
	return 0;
}