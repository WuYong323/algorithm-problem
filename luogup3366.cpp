#include<bits/stdc++.h>
#define N 5005
using namespace std;

struct edge{
	int u,v,w;
	bool operator<(const edge &t)const{
		return w<t.w;
	}
}e[N];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool krusal(){
	sort(e,e+m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=0;i<m;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y) {
			fa[x]=y;
			ans+=e[i].w;
			cnt++;
		}
	}
	return cnt==n-1;
}

int main()
{
	
	return 0;
}