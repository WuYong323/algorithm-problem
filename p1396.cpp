#include<bits/stdc++.h>
#define N 10005
#define M 20005
using namespace std;

struct edge{
	int u,v,w;
	bool operator <(const edge t){
		return w<t.w;
	}
}e[M];

int n,m,s,t;
int fa[N];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool krusal(){
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			if(find(s)==find(t)){
				cout<<e[i].w;
				return 0;
			}
		}
	}
}

int main()
{
	cin>>n>>m>>s>>t;
	int u,v,w;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	krusal();
	return 0;
}