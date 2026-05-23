#include<bits/stdc++.h>
using namespace std;

int f[6000];

int fd(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fd(f[x]);
}

void hb(int a,int b){
	f[fd(b)]=fd(a);
	return;
}

int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		hb(a,b);
	}
	for(int i=1;i<=p;++i){
		int a,b;
		cin>>a>>b;
		if(fd(a)==fd(b)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}