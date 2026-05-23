#include<bits/stdc++.h>
#define N 100005
#define mod 10007
#define ll long long
using namespace std;

int n,m;
int num[N];
int color[N];
ll ans;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>num[i];
	}
	for(int i=1;i<=n;++i){
		cin>>color[i];
	}
	for(int len=1;len<=(n-1)/2;++len){
		for(int i=1;i+len*2<=n;++i){
			if(color[i]==color[i+len*2]){
				ans+=(((2*i+2*len)%mod)*((num[i]+num[i+2*len])%mod)%mod);
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}