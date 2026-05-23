#include<bits/stdc++.h>
#define N 300005
using namespace std;

int n,m;
vector<int> e[N];
vector<int> graph[N];
int dfn[N],low[N],tot;
stack<int> s;
int scc[N],cnt;
int maxdis,farnode;

void tarjan(int x,int fa){
	dfn[x]=low[x]=++tot;
	s.push(x);
	for(int y:e[x]){
		if(y==fa) continue;
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]){
				int z;
				++cnt;
				do{
					z=s.top();
					s.pop();
					scc[z]=cnt;
				}while(y!=z);
			}
		}
		else{
			low[x]=min(low[x],dfn[y]);
		}
	}
}

void dfs(int u,int fa,int dis){
	if(dis>maxdis){
		maxdis=dis;
		farnode=u;
	}
	for(int v:graph[u]){
		if(v==fa) continue;
		dfs(v,u,dis+1);
	}
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	tarjan(1,0);
	if(!s.empty()){
        ++cnt;
        while(!s.empty()) {
            scc[s.top()]=cnt;
            s.pop();
        }
    }
	for(int i=1;i<=n;++i){
		for(int j:e[i]){
			int u=scc[i];
			int v=scc[j];
			if(u!=v){
				graph[u].push_back(v);
			}
		}
	}
	dfs(1,0,0);
	maxdis=0;
	dfs(farnode,0,0);
	cout<<maxdis;
	return 0;
}