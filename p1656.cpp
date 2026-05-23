#include<bits/stdc++.h>
#define N 155
using namespace std;

int n,m;
vector<int> e[N];
int dfn[N],low[N],tot;
vector<pair<int,int>> ans;

void tarjan(int x,int fa){
	dfn[x]=low[x]=++tot;
	for(int y:e[x]){
		if(y==fa) continue;
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]){
				ans.push_back({min(x,y),max(x,y)});
			}
		}
		else{
			low[x]=min(low[x],dfn[y]);
		}
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
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i,0);
	}
	sort(ans.begin(),ans.end());
	for(auto p:ans){
		cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}