#include<bits/stdc++.h>
#define int long long
#define N 100005
#define lz p<<1
#define rz p<<1|1
using namespace std;

int n,m;
int w[N],s[N];

struct node{
	int l,r,sum,add;
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

void update(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].sum+=k*(tr[p].r-tr[p].l+1);
		tr[p].add+=k;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(l<=m) update(lz,l,r,k);
	if(r>m) update(rz,l,r,k);
	pushup(p);
}

int query(int p,int l,int r){
	if(l<=tr[p].l&&r>=tr[p].r){
		return tr[p].sum;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int sum=0;
	if(l<=m) sum+=query(lz,l,r);
	if(r>m) sum+=query(rz,l,r);
	return sum;
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		w[i]=s[i]-s[i-1];
	}
	build(1,1,n+1);
	int op,l,r,k,d,p;
	for(int i=1;i<=m;++i){
		cin>>op;
		if(op==1){
			cin>>l>>r>>k>>d;
			update(1,l,l,k);
			update(1,l+1,r,d);
			int num=r-l;
			int t=k+num*d;
			update(1,r+1,r+1,-t);
		}
		if(op==2){
			cin>>p;
			cout<<query(1,1,p)<<endl;
		}
	}
	return 0;
}