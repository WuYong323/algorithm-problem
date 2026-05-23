#include<bits/stdc++.h>
#define N 10005
using namespace std;

int n,m;
vector<int> e[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;
int w[N];
int ans;
vector<int> graph[N];
int indeg[N];
int dp[N];


void tarjan(int x){
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	instk[x]=1;
	for(int y:e[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(instk[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){
		int y;
		++cnt;
		do{
			y=stk[top--];
			instk[y]=0;
			scc[y]=cnt;
			siz[cnt]+=w[y];
		}while(x!=y);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	int a,b;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		e[a].push_back(b);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i);
	}
	for(int u=1;u<=n;++u){
		for(int v:e[u]){
			int su=scc[u];
			int sv=scc[v];
			if(su!=sv){
				graph[su].push_back(sv);
				indeg[sv]++;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=cnt;++i){
		dp[i]=siz[i];
		if(indeg[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:graph[u]){
			dp[v]=max(dp[v],dp[u]+siz[v]);
			if(--indeg[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=cnt;++i){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}