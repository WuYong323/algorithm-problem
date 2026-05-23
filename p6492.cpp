#include<bits/stdc++.h>
#define lz p<<1
#define rz p<<1|1
#define N 200005
using namespace std;

int n,q,w[N];

struct node{
	int l,r,len,pre,suf,ans;
}tr[N*4];

node hebing(node l,node r){
	node res;
	res.len=l.len+r.len;
	res.l=l.l;
	res.r=r.r;
	
	if(l.pre==l.len&&l.r!=r.l) res.pre=l.len+r.pre;
	else res.pre=l.pre;
	
	if(r.suf==r.len&&l.r!=r.l) res.suf=r.len+l.suf;
	else res.suf=r.suf;
	
	res.ans=max(l.ans,r.ans);
	if(l.r!=r.l) res.ans=max(res.ans,l.suf+r.pre);
	
	return res;
}

void build(int p,int l,int r){
	tr[p]={w[l],w[l],1,1,1,1};
	if(l==r) return;
	int m=l+r>>1;
	build(lz,l,m);
	build(rz,m+1,r);
	tr[p]=hebing(tr[lz],tr[rz]);
}

void update(int p,int l,int r,int pos){
	if(l==r){
		tr[p].l=!tr[p].l;
		tr[p].r=!tr[p].r;
		return;
	}
	int m=l+r>>1;
	if(pos<=m) update(lz,l,m,pos);
	if(pos>m) update(rz,m+1,r,pos);
	tr[p]=hebing(tr[lz],tr[rz]);
}

int main()
{
	cin>>n>>q;
	build(1,1,n);
	int pos;
	for(int i=1;i<=q;++i){
		cin>>pos;
		update(1,1,n,pos);
		cout<<tr[1].ans<<endl;
	}
	return 0;
}