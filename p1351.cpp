#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define mod 10007
using namespace std;

vector<int> e[N];
int w[N];
int n,ans,maxx;


int main()
{
	cin>>n;
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int max1=0,max2=0;
		int t1=0,t2=0;
		for(int v:e[i]){
			if(w[v]>max1) max2=max1,max1=w[v];
			else if(w[v]>max2) max2=w[v];
			t1=(t1+w[v])%mod;
			t2=(t2+w[v]*w[v])%mod;
		}
		t1=t1*t1%mod;
		ans=(ans+t1+mod-t2)%mod;
		if(maxx<max1*max2) maxx=max1*max2;
	}
	cout<<maxx<<" "<<ans;
	return 0;
}