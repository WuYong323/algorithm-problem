#include<bits/stdc++.h>
#define N 305
using namespace std;

struct edge{
	int u,v,w;
	bool operator < (const edge &t) const{
		return w<t.w;
	}
}e[N*N+N];

int n;
int weigh=100005;
int len;
int ans;
int fa[N];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void krucal(){
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(e+1,e+1+len);
	for(int i=1;i<=len;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	
}

int main()
{
	cin>>n;
	int r;
	for(int i=1;i<=n;++i){
		cin>>r;
		e[++len].u=0;
		e[len].v=i;
		e[len].w=r;
	}
	int w;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>w;
			if(i<j) {
				e[++len].u=i;
				e[len].v=j;
				e[len].w=w;
			}
		}
	}
	krucal();
	cout<<ans;
	return 0;
}