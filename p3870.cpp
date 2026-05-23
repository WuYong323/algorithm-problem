#include<bits/stdc++.h>
#define lz p<<1
#define rz p<<1|1
#define N 100005
using namespace std;

int n,m;

struct node{
	int l,r,sum;
	bool add;
}tr[N*4];

void pushup(int p){
	tr[p].sum=tr[lz].sum+tr[rz].sum;
}

void pushdown(int p){
	if(tr[p].add){
		tr[lz].sum=(tr[lz].r-tr[lz].l+1)-tr[lz].sum;
		tr[rz].sum=(tr[rz].r-tr[rz].l+1)-tr[rz].sum;
		tr[lz].add=!tr[lz].add;
		tr[rz].add=!tr[rz].add;
		tr[p].add=0;
	}
}

void build(int p,int l,int r){
	tr[p]={l,r,0,0};
	if(l==r) return;
	int m=l+r>>1;
	build(lz,l,m);
	build(rz,m+1,r);
	pushup(p);
}

void update(int p,int x,int y){
	if(x<=tr[p].l&&y>=tr[p].r){
		tr[p].sum=(tr[p].r-tr[p].l+1)-tr[p].sum;
		tr[p].add=!tr[p].add;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m) update(lz,x,y);
	if(y>m) update(rz,x,y);
	pushup(p);
}

int query(int p,int x,int y){
	if(x<=tr[p].l&&y>=tr[p].r){
		return tr[p].sum;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int sum=0;
	if(x<=m) sum+=query(lz,x,y);
	if(y>m) sum+=query(rz,x,y);
	return sum;
}

int main()
{
	cin>>n>>m;
	build(1,1,n);
	
	int op,x,y;
	for(int i=1;i<=m;++i){
		cin>>op;
		if(op==0){
			cin>>x>>y;
			update(1,x,y);
		}
		if(op==1){
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	}
	return 0;
}