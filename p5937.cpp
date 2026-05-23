#include<bits/stdc++.h>
#define N 5005
using namespace std;

int n,m;

struct node{
	int l,r,t;
}a[4*N];

int f[4*N],b[4*N];
int l;

int find(int k){
	if(f[k]==k) return k;
	return f[k]=find(f[k]);
}

void hb(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		f[x]=y;
	}
}

int main()
{
	cin>>n>>m;
	string ch;
	for(int i=1;i<=m;++i){
		cin>>a[i].l>>a[i].r>>ch;
		a[i].l--;
		if(ch[0]=='o') a[i].t=1;
		else a[i].t=0;
		b[++l]=a[i].l;
		b[++l]=a[i].r;
	}
	sort(b+1,b+1+l);
	l=unique(b+1,b+1+l)-b-1;
	for(int i=1;i<=l*2;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		a[i].l=lower_bound(b+1,b+1+l,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+1+l,a[i].r)-b;
		if(a[i].t==0){
			if(find(a[i].l)==find(a[i].r+l)){
				cout<<i-1;
				return 0;
			}
			else{
				hb(a[i].l,a[i].r);
				hb(a[i].l+l,a[i].r+l);
			}
		}
		else{
			if(find(a[i].l)==find(a[i].r)){
				cout<<i-1;
				return 0;
			}
			else{
				hb(a[i].l,a[i].r+l);
				hb(a[i].l+l,a[i].r);
			}
		}
	}
	cout<<m;
	return 0;
}