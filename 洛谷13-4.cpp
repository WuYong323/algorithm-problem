#include<bits/stdc++.h>
using namespace std;

int m;
int lst[305][305];

int tu[305][305];
bool btu[305][305];
queue<pair<int,int>> q;
int lx[]={0,1,-1,0,0};
int ly[]={0,0,0,1,-1};

int ch(int a){
	if(a==-1){
		return 100000;
	}
	else{
		return a;
	}
}

int main()
{
	cin>>m;
	memset(lst,-1,sizeof(lst));
	for(int i=1;i<=m;i++){
		int x,y,t;
		cin>>x>>y>>t;
		for(int i=0;i<=4;i++){
			if(x+lx[i]>=0&&y+ly[i]>=0&&(lst[x+lx[i]][y+ly[i]]==-1||lst[x+lx[i]][y+ly[i]]>t)){
				lst[x+lx[i]][y+ly[i]]=t;
			}
		}
	}
	memset(btu,false,sizeof(btu));
	tu[0][0]=0;
	btu[0][0]=true;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		int s=tu[xx][yy]+1;
		if(lst[xx][yy]==-1){
			cout<<s-1;
			return 0;
		}
		for(int i=1;i<=4;i++){
			int u=xx+lx[i];
			int v=yy+ly[i];
			if(u>=0&&v>=0&&!btu[u][v]&&s<ch(lst[u][v])){
				btu[u][v]=true;
				q.push(make_pair(u,v));
				tu[u][v]=s;
			}
		}
	}
	cout<<-1;
	return 0;
}