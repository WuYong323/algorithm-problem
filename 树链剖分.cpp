#include<bits/stdc++.h>
#define N 100005
using namespace std;

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

int main()
{
	
	return 0;
}