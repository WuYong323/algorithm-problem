#include<bits/stdc++.h>
#define N 10005
using namespace std;

int n,m;
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;
vector<int> e[N];
int outdeg[N];
int ans;

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
			++siz[cnt];
		}while(x!=y);
	}
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;++i){
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
				outdeg[u]++;
			}
		}
	}
	int num=0;
	for(int i=1;i<=cnt;++i){
		if(outdeg[i]==0){
			ans+=siz[i];
			num++;
		}
	}
	if(num==1) cout<<ans;
	else cout<<0;
	return 0;
}