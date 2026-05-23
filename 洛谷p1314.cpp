#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

struct kuang{
	int w,v;
}ks[N];

struct qujian{
	int l,r;
}qj[N];

int n,m;
ll s;
int w,v;
int l,r;
ll cha1[N],cha2[N];

ll fun(int mid){
	memset(cha1,0,sizeof(cha1));
	memset(cha2,0,sizeof(cha2));
	ll num1=0,num2=0;
	for(int i=1;i<=n;++i){
		if(ks[i].w>=mid){
			num1++;
			num2+=ks[i].v;
		};
		cha1[i]=num1;
		cha2[i]=num2;
	}
	ll ans=0;
	for(int i=1;i<=m;++i){
		int l=qj[i].l;
		int r=qj[i].r;
		ans+=(cha1[r]-cha1[l-1])*(cha2[r]-cha2[l-1]);
	}
	return ans;
}

int main()
{
	cin>>n>>m>>s;
	int maxn=0;
	int minn=1e7;
	for(int i=1;i<=n;++i){
		cin>>ks[i].w>>ks[i].v;
		if(ks[i].w>maxn) maxn=ks[i].w;
		if(minn>ks[i].w) minn=ks[i].w;
	}
	for(int i=1;i<=m;++i){
		cin>>qj[i].l>>qj[i].r;
	}
	int l=minn-1;
	int r=maxn+1;
	while(l<r){
		int mid=l+r>>1;
		ll ans=fun(mid);
		if(s>ans) r=mid-1;
		if(s==ans){
			cout<<0;
			return 0;
		}
		if(s<ans) l=mid+1;
		if(l>=r) cout<<llabs(ans-s);
	}
	return 0;
}