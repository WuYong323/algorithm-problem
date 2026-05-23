#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define ls u<<1
#define rs u<<1|1
using namespace std;

int n;
int a1,b1,a2,b2;

struct line{
	int x1,x2,y;
	int tag;
	bool operator<(line &t){
		return y<t.y;
	}
}line[N];

struct tree{
	int l,r;
	int cnt,len;
}tr[N*8];

int x[N];

void build(int u,int l,int r){
	tr[u]={l,r,0,0};
	if(l==r) return;
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}

void pushup(int u){
	int l=tr[u].l;
	int r=tr[u].r;
	if(tr[u].cnt) tr[u].len=x[r+1]-x[l];
	else tr[u].len=tr[ls].len+tr[rs].len;
}

void modify(int u,int l,int r,int tag){
	if(l>tr[u].r||r<tr[u].l) return;
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].cnt+=tag;
		pushup(u);
		return;
	}
	modify(ls,l,r,tag);
	modify(rs,l,r,tag);
	pushup(u);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a1>>b1>>a2>>b2;
		line[i]={a1,a2,b1,1};
		line[n+i]={a1,a2,b2,-1};
		x[i]=a1;
		x[n+i]=a2;
	}
	n*=2;
	sort(line+1,line+1+n);
	sort(x+1,x+1+n);
	int s=unique(x+1,x+1+n)-x-1;
	build(1,1,s-1);
	ll ans=0;
	for(int i=1;i<n;++i){
		int l=lower_bound(x+1,x+1+s,line[i].x1)-x;
		int r=lower_bound(x+1,x+1+s,line[i].x2)-x;
		modify(1,l,r-1,line[i].tag);
		ans+=1ll*tr[1].len*(line[i+1].y-line[i].y);
	}
	cout<<ans;
	return 0;
}