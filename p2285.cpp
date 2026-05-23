#include<bits/stdc++.h>
#define N 10005
using namespace std;

struct sh{
	int t,x,y;
}shu[N];

int n,m;
int f[N];
int ans;

int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>shu[i].t>>shu[i].x>>shu[i].y;
	}
	for(int i=1;i<=m;++i){
		f[i]=1;
		for(int j=1;j<i;++j){
			if(dis(shu[i].x,shu[i].y,shu[j].x,shu[j].y)<=shu[i].t-shu[j].t){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	for(int i=1;i<=m;++i){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}