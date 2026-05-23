#include<bits/stdc++.h>
#define N 200005
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]
using namespace std;

int n,m,a[N];
vector<int> v;

srtuct node{
	int ch[2];
	int s;
}tr[N*22];

int root[N],idx;

void build(int &x,int l,int r){
	x=++idx;
	if(l==r) return;
	build(lc(x),l,m);
	build(rc(x),m+1,r);
}

void insert(int x,int &y,int l,int r,int v){
	y=++idx;
	tr[y]=tr[x];
	tr[y].s++;
	if(l==r) return;
	int m=l+r>>1;
	if(v<=m) insert(lc(x),lc(y),l,m,v);
	else insert(lc(x),rc(y),m+1,r,v);
}

int query(int x,int y,int l,int r,int k){
	if(l==r) return l;
	int m=l+r>>1;
	int s=tr[lc(y)].s-tr[lc(x)].s;
	if(k<=s) return query(lc(x),lc(y),l,m,k);
	else return query(rc(x),rc(y),m+1,r,k-s);
}

int main()
{
	build(root[0],1,n);
	for(int i=1;i<=n;++i){
		insert(root[i-1],root[i],1,n,a[i]);
	}
	scanf("%d%d%d",&l,&r,&k);
	
	query(root[l-1],root[r],1,n,k);
	return 0;
}