#include<bits/stdc++.h>
#define N 100005
using namespace std;

int fa[N],ans[N],n,m;
char name[N];
int cnt;

int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}

void merge(int x,int y){
	fa[find(x)]=find(y);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		cin>>name[i];
	}
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		if(name[u]==name[v]) merge(u,v);
	}
	char ch;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>ch;
		if(find(u)==find(v)&&name[u]!=ch) ans[++cnt]=0;
		else ans[++cnt]=1;
	}
	for(int i=1;i<=cnt;++i) cout<<ans[i];
	return 0;
}