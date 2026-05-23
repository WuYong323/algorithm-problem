#include<bits/stdc++.h>
#define N 105
using namespace std;

int n,m;
char graph[N][N];
bool vis[N][N];
int ans;
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};

void bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	vis[i][j]=1;
	while(q.size()){
		auto t=q.front();
		q.pop();
		int x=t.first;
		int y=t.second;
		for(int k=0;k<4;++k){
			int nx=x+rx[k];
			int ny=y+ry[k];
			if(!vis[nx][ny]&&graph[nx][ny]>='1'&&graph[nx][ny]<='9'){
				q.push({nx,ny});
				vis[nx][ny]=1;
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(graph[i][j]<='9'&&graph[i][j]>='1'&&!vis[i][j]){
				bfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}