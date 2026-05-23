#include<bits/stdc++.h>
using namespace std;

int n,m;
char lst[105][105];
int ans;
int lx[]={0,0,1,-1,-1,1,-1,1};
int ly[]={1,-1,0,0,1,-1,-1,1};


void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int xx=x+lx[i];
		int yy=y+ly[i];
		if(xx>=0&&xx<=n&&yy>=0&&yy<=m&&lst[xx][yy]!='.'){
			lst[xx][yy]='.';
			dfs(xx,yy);
		}
	}
	return;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>lst[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(lst[i][j]=='W'){
				lst[i][j]='.';
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}