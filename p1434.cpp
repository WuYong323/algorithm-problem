#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y,h;
    bool operator<(const Point& other)const{
        return h<other.h;
    }
};

int r,c;
int grid[105][105];
int dp[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
    cin>>r>>c;
    vector<Point> points;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin>>grid[i][j];
            points.push_back({i,j,grid[i][j]});
            dp[i][j]=1;
        }
    }
    sort(points.begin(),points.end());
    int ans=1;
    for (const auto& p:points) {
        int x=p.x,y=p.y;
        for (int k=0;k<4;++k) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<1||nx>r||ny<1||ny>c) continue;
            if(grid[nx][ny]<grid[x][y]){
                dp[x][y]=max(dp[x][y],dp[nx][ny] + 1);
            }
        }
        ans=max(ans,dp[x][y]);
    }
    cout<<ans;
    return 0;
}