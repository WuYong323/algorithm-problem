#include<bits/stdc++.h>
#define N 50005
using namespace std;

int n,ans=N;
int h[N],ne[N*2],e[N*2],idx;
int center;
int res;
int vis[N];

void add(int a,int b){
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}

int dfs(int u){
	vis[u]=1;
	int size=0;
	int sum=1;
	for(int i=h[u];i;i=ne[i]){
		int j=e[i];
		if(vis[j]) continue;
		int s=dfs(j);
		size=max(size,s);
		sum+=s;
	}
	if(ans>max(size,n-sum)){
		ans=max(size,n-sum);
		center=u;
	}
	else if(ans==max(size,n-sum)&&center>u){
		center=u;
	}
	return sum;
}

void bfs(int u){
	queue<int> q;
	vector<int> dis(n+1,-1);
	q.push(u);
	dis[u]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		res+=dis[u];
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1);
	bfs(center);
	cout<<center<<" "<<res;
	return 0;
}