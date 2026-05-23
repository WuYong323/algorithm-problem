#include<bits/stdc++.h>
#define int long long
#define N 100005
#define lz p<<1
#define rz p<<1|1
using namespace std;

int n,q,m,w[N];

struct node{
	int l,r,sum,add,mul;
	bool cnt_mul;
}tr[N*4];

void pushup(int p){
	tr[p].sum=tr[lz].sum+tr[rz].sum;
}

void build(int p,int l,int r){
	tr[p]={l,r,w[l]%m,0,1,0};
	if(l==r) return;
	int mid=l+r>>1;
	build(lz,l,mid);
	build(rz,mid+1,r);
	pushup(p);
}

void pushdown(int p){
	if(tr[p].cnt_mul){
		tr[lz].sum*=tr[p].mul,tr[lz].sum%=m;
		tr[rz].sum*=tr[p].mul,tr[rz].sum%=m;
		tr[lz].mul*=tr[p].mul,tr[lz].mul%=m;
		tr[rz].mul*=tr[p].mul,tr[rz].mul%=m;
		tr[lz].add*=tr[p].mul,tr[lz].add%=m;
		tr[rz].add*=tr[p].mul,tr[rz].add%=m;
		tr[lz].cnt_mul=1;
		tr[rz].cnt_mul=1;
		tr[p].mul=1;
		tr[p].cnt_mul=0;
	}
	if(tr[p].add){
		tr[lz].sum+=tr[p].add*(tr[lz].r-tr[lz].l+1),tr[lz].sum%=m;
		tr[rz].sum+=tr[p].add*(tr[rz].r-tr[rz].l+1),tr[rz].sum%=m;
		tr[lz].add+=tr[p].add,tr[lz].add%=m;
		tr[rz].add+=tr[p].add,tr[rz].add%=m;
		tr[p].add=0;
	}
}

void update1(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].sum*=k,tr[p].sum%=m;
		tr[p].mul*=k,tr[p].mul%=m;
		tr[p].cnt_mul=1;
		tr[p].add*=k,tr[p].add%=m;
		return;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(l<=mid) update1(lz,l,r,k);
	if(r>mid) update1(rz,l,r,k);
	pushup(p);
}

void update2(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k,tr[p].sum%=m;
		tr[p].add+=k,tr[p].add%=m;
		return;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(l<=mid) update2(lz,l,r,k);
	if(r>mid) update2(rz,l,r,k);
	pushup(p);
}

int query(int p,int l,int r){
	if(l<=tr[p].l&&r>=tr[p].r){
		return tr[p].sum;
	}
	int mid=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int ans=0;
	if(l<=mid) ans+=query(lz,l,r),ans%=m;
	if(r>mid) ans+=query(rz,l,r),ans%=m;
	return ans%=m;
}

signed main()
{
	cin>>n>>q>>m;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	build(1,1,n);
	int op,l,r,k;
	for(int i=1;i<=q;++i){
		cin>>op;
		if(op==1){
			cin>>l>>r>>k;
			update1(1,l,r,k);
		}
		if(op==2){
			cin>>l>>r>>k;
			update2(1,l,r,k);
		}
		if(op==3){
			cin>>l>>r;
			cout<<query(1,l,r)<<endl;
		}
	}
	return 0;
}