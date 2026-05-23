#include<bits/stdc++.h>
#define N 5005
#define inf 0x7f7f7f7f
using namespace std;

struct edge{
	int v,w;
};

int n,m,cnt,ans,a,b,c;
vector<edge> e[N];
int dis[N],vis[N]; 
priority_queue<pair<int,int>> q;

bool prime(int s){
	for(int i=1;i<=n;++i) dis[i]=inf;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=dis[u];
		cnt++;
		for(auto ed:e[u]){
			int v=ed.v;
			int w=ed.w;
			if(dis[v]>w){
				dis[v]=w;
				q.push({-w,v});
			}
		}
	}
	return cnt==n;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	if(prime(1)){
		cout<<ans;
	}
	else{
		cout<<"orz";
	}
	return 0;
}