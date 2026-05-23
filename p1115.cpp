#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[200005];
ll minn=1e18,maxn;

int main()
{
	cin>>n;
	int num;
	for(int i=1;i<=n;++i){
		cin>>num;
		a[i]=a[i-1]+num;
	}
	for(int i=1;i<=n;++i){
		minn=min(minn,a[i-1]);
		maxn=max(maxn,a[i]-minn);
	}
	cout<<maxn;
	return 0;
}