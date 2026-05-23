#include<bits/stdc++.h>
#define ll long long
#define lz p<<1
#define rz p<<1|1
#define N 100005
using namespace std;

int n,m;
ll w[N];

struct node{
	ll l,r,sum,add;
}tr[N*4];

void pushup(int p){
	tr[p].sum=tr[lz].sum+tr[rz].sum;
}

void pushdown(int p){
	if(tr[p].add){
		tr[lz].sum+=tr[p].add*(tr[lz].r-tr[lz].l+1);
		tr[rz].sum+=tr[p].add*(tr[rz].r-tr[rz].l+1);
		tr[lz].add+=tr[p].add;
		tr[rz].add+=tr[p].add;
		tr[p].add=0;
	}
}

void build(int p,int l,int r){
	tr[p]={l,r,w[l],0};
	if(l==r) return;
	int m=l+r>>1;
	build(lz,l,m);
	build(rz,m+1,r);
	pushup(p);
}

void update(int p,int x,int y,ll k){
	if(x<=tr[p].l&&y>=tr[p].r){
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
		tr[p].add+=k;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m) update(lz,x,y,k);
	if(y>m) update(rz,x,y,k);
	pushup(p);
}

ll query(int p,int x,int y){
	if(x<=tr[p].l&&y>=tr[p].r){
		return tr[p].sum;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	ll sum=0;
	if(x<=m) sum+=query(lz,x,y);
	if(y>m) sum+=query(rz,x,y);
	return sum;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	build(1,1,n);
	int op,x,y;
	ll k;
	for(int i=1;i<=m;++i){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update(1,x,y,k);
		}
		if(op==2){
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	}
	return 0;
}