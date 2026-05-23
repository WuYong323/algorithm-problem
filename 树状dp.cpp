#include<bits/stdc++.h>
#define N 10010 
using namespace std;

int n,ans;
bool vis[N];
int h[N],e[N*2],w[N*2],ne[N*2],idx; //邻接表

void add(int a,int b,int c){
	e[++idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx;
}

int dfs(int u){
	vis[u]=1;
	int d1=0;
	int d2=0;
	for(int i=h[u];i;i=ne[i]){
		int j=e[i];
		if(vis[j]) continue;
		int d=dfs(j)+w[i];
		if(d>=d1){
			d2=d1,d1=d;
			from2[u]=from1[u];
			from1[u]=v;
		}
		else if(d>d2){
			d2=d;
			from2[u]=v;
		}
	}
	if(ans<d1+d2){
		ans=d1+d2;
		D1=d1,D2=d2;
		center=u;
	}
	return d1;
}

int main()
{
	cin>>n;
	for(int i=1;i<n;++i){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}