#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
	int l,r;
}e[105];

int t;
int a[105];


void solve(){
	memset(e,0,sizeof(e));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int p,l,r;
	int flage=0;
	for(int i=1;i<=q;++i){
		cin>>p>>l>>r;
		if(e[p].l==0||l>=e[p].l) e[p].l=l;
		else if(r<e[p].l){
			flage=1;
		}
		if(e[p].r==0||r<=e[p].r) e[p].r=r;
		else if(l>e[p].r){
			flage=1;
		}
	}
	if(flage) {
		cout<<-1<<endl;
		return;
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(e[i].l!=0){
			if(a[i]<e[i].l||a[i]>e[i].r)
				ans+=min(abs(a[i]-e[i].l),abs(a[i]-e[i].r));
		}
	}
	cout<<ans<<endl;
}

int main()
{
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}