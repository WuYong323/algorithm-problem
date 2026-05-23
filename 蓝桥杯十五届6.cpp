#include <bits/stdc++.h>
using namespace std;

int n,k;
int graph[11][11];
int rx[8]={-1,-1,0,1,1,1,0,-1};
int ry[8]={0,1,1,1,0,-1,-1,-1};
int cnt[11][11][11][11];
vector<int> path;
int vis[11][11];

bool dfs(int x,int y){
  if(x==n&&y==n){
    if(path.size()==n*n-1){
      return true;
    }
    else return false;
  }
  vis[x][y]=1;
  for(int i=0;i<8;++i){
    int nx=x+rx[i];
    int ny=y+ry[i];
    if(nx>n||nx<1||ny>n||ny<1) continue;
    if(graph[nx][ny]!=(graph[x][y]+1)%k) continue;
    if(i%2&&(cnt[x][ny][nx][y]||cnt[nx][y][x][ny])) continue;
    cnt[x][y][nx][ny]=1;
    path.push_back(i);
    if(dfs(nx,ny)) return true;
    path.pop_back();
    cnt[x][y][nx][ny]=false;
  }
  vis[x][y]=false;
  return false;
}

int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      cin>>graph[i][j];
    }
  }
  if(!dfs(1,1)){
    cout<<-1;
  }
  else{
    for(int x:path){
      cout<<x;
    }
  }
  return 0;
}