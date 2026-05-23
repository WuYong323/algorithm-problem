#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define lz p<<1
#define rz p<<1|1
using namespace std;

int n,q;
int a[N];

int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

struct node{
	int l,r,maxn,add,set;
	bool cnt;
}tr[N*4];

void pushup(int p){
	tr[p].maxn=max(tr[lz].maxn,tr[rz].maxn);
}

void build(int p,int l,int r){
	tr[p]={l,r,a[l],0,0,0};
	if(l==r) return;
	int m=l+r>>1;
	build(lz,l,m);
	build(rz,m+1,r);
	pushup(p);
}

void pushdown(int p){
	if(tr[p].cnt){
		tr[lz].maxn=tr[p].set;
		tr[rz].maxn=tr[p].set;
		tr[lz].set=tr[p].set;
		tr[rz].set=tr[p].set;
		tr[lz].cnt=1;
		tr[rz].cnt=1;
		tr[lz].add=0;
		tr[rz].add=0;
		tr[p].set=0;
		tr[p].cnt=0;
	}
	
	if(tr[p].add){
		tr[lz].maxn+=tr[p].add;
		tr[rz].maxn+=tr[p].add;
		tr[lz].add+=tr[p].add;
		tr[rz].add+=tr[p].add;
		tr[p].add=0;
	}
}

void update1(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].maxn=k;
		tr[p].set=k;
		tr[p].cnt=1;
		tr[p].add=0;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(l<=m) update1(lz,l,r,k);
	if(r>m) update1(rz,l,r,k);
	pushup(p);
}

void update2(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].maxn+=k;
		tr[p].add+=k;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(l<=m) update2(lz,l,r,k);
	if(r>m) update2(rz,l,r,k);
	pushup(p);
}

int query(int p,int l,int r){
	if(l<=tr[p].l&&r>=tr[p].r){
		return tr[p].maxn;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int maxn=LLONG_MIN;
	if(l<=m) maxn=max(maxn,query(lz,l,r));
	if(r>m) maxn=max(maxn,query(rz,l,r));
	return maxn;
}

signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	int op,l,r,x;
	for(int i=1;i<=q;++i){
		op=read();
		if(op==1){
			l=read(),r=read(),x=read();
			update1(1,l,r,x);
		}
		if(op==2){
			l=read(),r=read(),x=read();
			update2(1,l,r,x);
		}
		if(op==3){
			l=read(),r=read();
			cout<<query(1,l,r)<<endl;
		}
	}
	return 0;
}