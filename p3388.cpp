#include<bits/stdc++.h>
#define N 20005
using namespace std;

int n,m;
vector<int> e[N];
int dfn[N],low[N],tot;
int root;
set<int> ans;

void tarjan(int x){
	dfn[x]=low[x]=++tot;
	int child=0;
	for(int y:e[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				child++;
				if(x!=root||child>1){
					ans.insert(x);
				}
			}
		}
		else {
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
		root=i;
		tarjan(i);
	}
	cout<<ans.size()<<endl;
	for(int x:ans){
		cout<<x<<" ";
	}
	return 0;
}