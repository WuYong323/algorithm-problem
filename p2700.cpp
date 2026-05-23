#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

struct edge{
	int u,v,w;
	bool operator < (const edge &t) const{
		return w>t.w;
	}
}e[N];

int fa[N];
int n,k;
int di[N];
ll ans;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void krucal(){
	sort(e+1,e+n);
	for(int i=1;i<n;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(di[x]&&di[y]) continue;
		fa[x]=y;
		ans-=e[i].w;
		if(di[x]) di[y]=1;
		else if(di[y]) di[x]=1;
	}
	
}

int main()
{
	cin>>n>>k;
	int id;
	for(int i=0;i<=n;++i) fa[i]=i;
	for(int i=1;i<=k;++i){
		cin>>id;
		di[id]=1;
	}
	int u,v,w;
	for(int i=1;i<n;++i){
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
		ans+=w;
	}
	krucal();
	cout<<ans;
	return 0;
}