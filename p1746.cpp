#include<bits/stdc++.h>
#define N 1005
using namespace std;

int n;
int a1,b1,a2,b2;
char graph[N][N];
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
int vis[N][N];

void bfs(){
	queue<pair<int,int>> q;
	q.push({a1,b1});
	vis[a1][b1]=1;
	while(q.size()){
		auto t=q.front();
		q.pop();
		int x=t.first;
		int y=t.second;
		for(int i=0;i<4;++i){
			int nx=x+rx[i];
			int ny=y+ry[i];
			if(graph[nx][ny]=='0'&&nx>=1&&ny<=n&&ny>=1&&nx<=n&&!vis[nx][ny]){
				q.push({nx,ny});
				vis[nx][ny]=vis[x][y]+1;
			}
		}
	}
}

int main()
{
	cin>>n;
	char ch;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>graph[i][j];
		}
	}
	cin>>a1>>b1>>a2>>b2;
	bfs();
	cout<<vis[a2][b2]-1;
	return 0;
}