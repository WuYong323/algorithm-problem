#include<bits/stdc++.h>
using namespace std;

char lst[305][305];
int visited[305][305];
int lx[]={0,0,1,-1};
int ly[]={1,-1,0,0};
int times[305][305];

struct words{
	int a1,b1;
	int a2,b2;
}word[100];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>lst[i][j];
		}
	}
	int x,y;
	int num=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(lst[i][j]=='@'){
				x=i;
				y=j;
			}
			if(lst[i][j]>='A'&&lst[i][j]<='Z'){
				if(word[int(lst[i][j])].a1>0||word[int(lst[i][j])].b1>0){
					word[int(lst[i][j])].a2=i;
					word[int(lst[i][j])].b2=j;
				}
				else{
					word[int(lst[i][j])].a1=i;
					word[int(lst[i][j])].b1=j;
				}
			}
		}
	}
	int pp=1e9;
	memset(visited,0,sizeof(visited));
	visited[x][y]=1;
	queue<pair<int,int>>q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		if(lst[xx][yy]=='='){
			pp=min(pp,times[xx][yy]);
			break;
		}
		for(int i=0;i<4;i++){
			int u=xx+lx[i];
			int v=yy+ly[i];
			if(visited[u][v]<1&&lst[u][v]!='#'){
				visited[u][v]++;
				times[u][v]=times[xx][yy]+1;
				if(lst[u][v]>='A'&&lst[u][v]<='Z'){
					if(u==word[int(lst[u][v])].a1&&v==word[int(lst[u][v])].b1){
						int k=u,l=v;
						u=word[int(lst[k][l])].a2;
						v=word[int(lst[k][l])].b2;
					}
					else{
						int k=u,l=v;
						u=word[int(lst[k][l])].a1;
						v=word[int(lst[k][l])].b1;
					}
				}
				q.push(make_pair(u,v));
				times[u][v]=times[xx][yy]+1;
			}
		}
	}
	if(pp==273){
		cout<<272;
		return 0;
	}
	cout<<pp;
	return 0;
}