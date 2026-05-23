#include<bits/stdc++.h>
#define N 505
#define inf 0x3f3f3f3f
using namespace std;

int a,b;
int f[N][N];
int ans,res;
int dis[N],vis[N];

int prime(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=b;++i) dis[i]=inf;
	dis[0]=0;
	for(int i=0;i<=b;++i){
		int u=503;
		for(int j=0;j<=b;++j){
			if(!vis[j]&&dis[j]<dis[u]) u=j;
		
		}
		vis[u]=1;
		ans+=dis[u];
		for(int j=0;j<=b;++j){
			if(!vis[j]&&f[u][j]<dis[j]){
				dis[j]=f[u][j];
			}
		}
	}
	return ans;
}


int main()
{
	cin>>a>>b;
	int num;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=b;++i) f[0][i]=f[i][0]=a;
	
	for(int i=1;i<=b;++i){
		for(int j=1;j<=b;++j){
			cin>>num;
			if(i!=j&&num!=0) f[i][j]=num;;
		}
	}
	ans=prime();
	cout<<ans;
	return 0;
}