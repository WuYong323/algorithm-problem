#include<bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

const int M=1e6+10;
int n;
int a[N],b[N];
int sum=0;
int ans=1e18;
int p[4*M];

signed main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		sum+=b[i];
	}
	for(int i=0;i<=1e6;++i){
		for(int j=1;(j-1)*i<=1e6&&j<=n;++j){
			p[a[j]-(j-1)*i+2*M]+=b[j];
			ans=min(ans,sum-p[a[j]-(j-1)*i+2*M]);
		}
		for(int j=1;(j-1)*i<=1e6&&j<=n;++j){
			p[a[j]-(j-1)*i+2*M]-=b[j];
		}
	}
	cout<<ans;
	return 0;
}