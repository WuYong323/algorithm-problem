#include<bits/stdc++.h>
#define N 3005
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

vector<int> e[N];
vector<int> graph[N];
int n,p,r,id;
int w[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],cnt;
int nw[N];
int indeg[N];
ll ans;
int vis[N];

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
	if(low[x]==dfn[x]){
		int y;
		++cnt;
		int wi=inf;
		do{
			y=stk[top--];
			instk[y]=0;
			scc[y]=cnt;
			if(w[y]!=-1) wi=min(wi,w[y]);
		}while(x!=y);
		nw[cnt]=wi;
	}
}

void bfs(){
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(w[i]!=-1){
			vis[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:e[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			cout<<"NO\n"<<i;
			return;
		}
	}
}

int main()
{
	cin>>n>>p;
	for(int i=1;i<=n;++i) w[i]=-1;
	for(int i=1;i<=n;++i) nw[i]=-1;
	for(int i=1;i<=p;++i){
		cin>>id;
		cin>>w[id];
	}
	cin>>r;
	int a,b;
	for(int i=1;i<=r;++i){
		cin>>a>>b;
		e[a].push_back(b);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j:e[i]){
			int u=scc[i];
			int v=scc[j];
			if(u!=v){
				indeg[v]++;
			}
		}
	}
	bool flage=0;
	for(int i=1;i<=cnt;++i){
		if(indeg[i]==0){
			if(nw[i]==inf){
				flage=1;
				break;
			}
			else{
				ans+=nw[i];
			}
		}
	}
	if(!flage) cout<<"YES\n"<<ans;
	else{
		bfs();
	}
	return 0;
}