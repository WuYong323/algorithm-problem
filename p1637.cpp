#include<bits/stdc++.h>
#define int long long
#define N 30005
using namespace std;

int n,m;
int a[N],b[N];
int bit1[N],bit2[N];
int left_cnt[N],right_cnt[N];

int lowbit(int x){
	return x&-x;
}

void update(int bit[],int x,int val){
	while(x<=m){
		bit[x]+=val;
		x+=lowbit(x);
	}
}

int query(int bit[],int x){
	int res=0;
	while(x>0){
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	}
	for(int i=1;i<=n;++i){
		left_cnt[i]=query(bit1,a[i]-1);
		update(bit1,a[i],1);
	}
	for(int i=n;i>=1;--i){
		right_cnt[i]=query(bit2,m)-query(bit2,a[i]);
		update(bit2,a[i],1);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=left_cnt[i]*right_cnt[i];
	}
	cout<<ans;
	return 0;
}