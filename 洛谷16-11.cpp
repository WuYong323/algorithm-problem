#include<bits/stdc++.h>
using namespace std;

int f[2020];

int fd(int x){
	if(f[x]!=x){
		return f[x]=fd(f[x]);
	}
	return f[x];
}

void hb(int a,int b){
	f[fd(b)]=fd(a);
}

bool same(int x,int y){
	return fd(x)==fd(y);
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=2010;++i){
		f[i]=i;
	}
	int p,q;
	char o;
	for(int i=1;i<=m;++i){
		cin>>o>>p>>q;
		if(o=='F'){
			hb(p,q);
		}
		else if(o=='E'){
			hb(p+n,q);
			hb(p,q+n);
		}
	}
	set<int> ans;
	for(int i=1;i<=n;++i){
		ans.insert(fd(i));
	}
	cout<<ans.size();
	return 0;
}