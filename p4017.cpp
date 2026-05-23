#include<bits/stdc++.h>
#define N 5005
using namespace std;

int n,m;
vector<int> e[N];
int indeg[N],outdeg[N];
queue<int> q;
int ans;
int dp[N];

const int mod=80112002;

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		e[a].push_back(b);
		indeg[b]++;
		outdeg[a]++;
	}
	for(int i=1;i<=n;++i){
		if(indeg[i]==0){
			q.push(i);
			dp[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:e[u]){
			dp[v]=(dp[u]+dp[v])%mod;
			indeg[v]--;
			if(indeg[v]==0){
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(outdeg[i]==0){
			ans=(ans+dp[i])%mod;
		}
	}
	cout<<ans;
	return 0;
}