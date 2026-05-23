#include<bits/stdc++.h>
#define N 100005
using namespace std;

struct node{
	int falen,chlen;
}tr[N];

int maxlen,maxid;
vector<int> e[N];
int n,k;
int u,v;

priority_queue<int> q;

void dfs1(int fa,int u,int deep){
	if(e[u].size()==1&&fa){
		if(deep>maxlen) maxlen=deep,maxid=u;
		return;
	}
	for(int v:e[u]){
		if(v!=fa) dfs1(u,v,deep+1);
	}
}

int dfs2(int fa,int u,int deep){
	tr[u].falen=deep;
	if(e[u].size()==1&fa) return tr[u].chlen=1;
	for(int v:e[u]){
		if(v==fa) continue;
		tr[u].chlen=max(tr[u].chlen,dfs2(u,v,deep+1));
	}
	return ++tr[u].chlen;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(0,1,1);
	dfs2(0,maxid,1);
	for(int i=1;i<=n;++i){
		q.push(min(tr[i].chlen,tr[i].falen));
	}
	for(int i=1;i<=k;++i) q.pop();
	cout<<q.top();
	return 0;
}