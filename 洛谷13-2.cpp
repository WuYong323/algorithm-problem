#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
int tu[405][405];
bool btu[405][405];
int lx[]={-1,-1,-2,-2,1,1,2,2};
int ly[]={2,-2,-1,1,-2,2,-1,1};
queue<pair<int,int>>q;

int main()
{
	cin>>n>>m>>x>>y;
	memset(tu,-1,sizeof(tu));
	memset(btu,false ,sizeof(btu));
	tu[x][y]=0;
	btu[x][y]=true;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		for(int i=0;i<8;i++){
			int u=xx+lx[i],v=yy+ly[i];
			if(u<1||u>n||v<1||v>m||btu[u][v]){
				continue;
			}
			btu[u][v]=true;
			q.push(make_pair(u,v));
			tu[u][v]=tu[xx][yy]+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<tu[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}