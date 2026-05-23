#include<iostream>
#include<algorithm>
using namespace std;

struct tree{
	int to,next;
}t[220];

int num;
long long ans=1e18;
int head[110],w[110],size[110];
long long f[110];

void add(int from,int to){
	t[++num].to=to;
	t[num].next=head[from];
	head[from]=num;
	return;
}

void dfs(int u,int fa,int dep){
	size[u]=w[u];
	for(int i=head[u];i;i=t[i].next){
		if(t[i].to!=fa){
			dfs(t[i].to,u,dep+1);
			size[u]+=size[t[i].to];
		}
	}
	f[1]+=w[u]*dep;
	return;
}

void dp(int u,int fa){
	for(int i=head[u];i;i=t[i].next){
		if(t[i].to!=fa){
			f[t[i].to]=f[u]+size[1]-size[t[i].to]*2;
			dp(t[i].to,u);
		}
		ans=min(ans,f[u]);
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;++i){
		cin>>w[i]>>a>>b;
		if(a) add(i,a),add(a,i);
		if(b) add(i,b),add(b,i);
	}
	dfs(1,0,0);
	dp(1,0);
	cout<<ans;
	return 0;
}