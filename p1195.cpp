#include<bits/stdc++.h>
#define N 1005
#define M 10005
using namespace std;

struct edge{
	int u,v,w;
	bool operator < (const edge& t) const{
		return w<t.w;
	}
}e[M];

int n,m,k;
int fa[N];
int ans;
int num;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void krucal(){
	sort(e+1,e+1+m);
	num=n-k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		if(num==0) break;
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			num--;
			ans+=e[i].w;
		}
	}
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	krucal();
	if(num) cout<<"No Answer";
	else cout<<ans;
	return 0;
}