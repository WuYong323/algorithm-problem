#include<bits/stdc++.h>
#define lz p<<1
#define rz p<<1|1
#define N 100005
using namespace std;

int l,t,o;

struct node{
	int l,r,num,set;
}tr[N*4];

int bit(int color){
	return 1<<(color-1);
}

void pushup(int p){
	tr[p].num=tr[lz].num|tr[rz].num;
}

int count(int num){
	return __builtin_popcount(num);
}

void build(int p,int l,int r){
	tr[p]={l,r,1<<0,0};
	if(l==r) return;
	int m=l+r>>1;
	build(lz,l,m);
	build(rz,m+1,r);
	pushup(p);
}

void pushdown(int p){
	if(tr[p].set){
		int color_bit=bit(tr[p].set);
		tr[lz].num=color_bit;
		tr[rz].num=color_bit;
		tr[lz].set=tr[p].set;
		tr[rz].set=tr[p].set;
		tr[p].set=0;
	}
}

void update(int p,int l,int r,int color){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].num=bit(color);
		tr[p].set=color;
		return;
	}
	pushdown(p);
	int m=(tr[p].l+tr[p].r)>>1;
	if(l<=m) update(lz,l,r,color);
	if(r>m) update(rz,l,r,color);
	pushup(p);
}

int query(int p,int l,int r){
	if(l<=tr[p].l&&r>=tr[p].r){
		return tr[p].num;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	int ans=0;
	if(l<=m) ans=ans|query(lz,l,r);
	if(r>m) ans=ans|query(rz,l,r);
	return ans;
}

int main()
{
	cin>>l>>t>>o;
	build(1,1,l);
	char op;
	int l,r,k;
	for(int i=1;i<=o;++i){
		cin>>op;
		if(op=='C'){
			cin>>l>>r>>k;
			if(l>r) swap(l,r);
			update(1,l,r,k);
		}
		if(op=='P'){
			cin>>l>>r;
			if(l>r) swap(l,r);
			int num=query(1,l,r);
			cout<<count(num)<<endl;
		}
	}
	return 0;
}