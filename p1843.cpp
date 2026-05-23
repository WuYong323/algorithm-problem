#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,a,b;
int w[N];

bool check(int mid){
	int res=0;
	for(int i=1;i<=n;++i){
		if(w[i]<=mid*a) continue;
		else{
			if((w[i]-mid*a)%b==0) res+=(w[i]-mid*a)/b;
			else res+=((w[i]-mid*a)/b+1);
		}
	}
	return res<=mid;
}

signed main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	int l=0,r=1e9;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}