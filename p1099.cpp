#include<bits/stdc++.h>
#define N 305
using namespace std;

int n,s;
struct edge{
	int v,w;
};
vector<edge> e[N];
int dep[N],f[N],c;
int lj[N],pre[N],vis[N];
int cnt;

void dfs(int u,int fa){
	f[u]=fa;
	for(auto ed:e[u]){
		int v=ed.v;
		int w=ed.w;
		if(vis[v]||v==fa) continue;
		dep[v]=dep[u]+w;
		if(dep[v]>dep[c]) c=v;
		dfs(v,u);
	}
}

void lujing(){
	dfs(1,0);
	dep[c]=0;
	dfs(c,0);
	for(int u=c;u;u=f[u]){
		lj[++cnt]=u;
		pre[cnt]=dep[u];
	}
	reverse(lj+1,lj+1+cnt);
	reverse(pre+1,pre+1+cnt);
}

int main()
{
	cin>>n>>s;
	int u,v,w;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	lujing();
	int ans=1<<30;
	for(int i=1;i<=cnt;++i){
		for(int j=i;j<=cnt;++j){
			if(pre[j]-pre[i]<=s){
				memset(vis,0,sizeof(vis));
				for(int k=i;k<=j;++k){
					vis[lj[k]]=1;
				}
				int res=0;
				for(int k=i;k<=j;++k){
					dep[lj[k]]=0,c=0;
					dfs(lj[k],0);
					res=max(res,dep[c]);
				}
				ans=min(ans,res);
			}
		}
	}
	cout<<ans;
	return 0;
}