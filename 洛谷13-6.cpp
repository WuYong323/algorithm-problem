#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int sx,sy,fx,fy;
bool btu[7][7];
int ans=0;
int lx[]={0,0,1,-1};
int ly[]={1,-1,0,0};

void back_t(int a,int b){
	if(a==fx&&b==fy){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int xx=a+lx[i];
		int yy=b+ly[i];
		if(!btu[xx][yy]&&xx>0&&yy>0&&xx<=n&&yy<=m){
			btu[xx][yy]=true;
			back_t(xx,yy);
			btu[xx][yy]=false;
		}	
	}
}

int main()
{
	memset(btu,false,sizeof(btu));
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		btu[x][y]=true;
	}
	btu[sx][sy]=true;
	back_t(sx,sy);
	cout<<ans;
	return 0;
}