#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,d;
vector<int> e[N];
int vis[N];

void bfs(){
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:e[u]){
			if(!vis[v]){
				q.push(v);
				vis[v]=vis[u]+1;
			}
		}
	}
}

int main()
{
	cin>>n>>d;
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs();
	int ans=0;
	for(int i=1;i<=n;++i){
		if(vis[i]-1<=d){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}