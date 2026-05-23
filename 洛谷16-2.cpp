#include<bits/stdc++.h>
using namespace std;

int f[1100];

int fd(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fd(f[x]);
}

void hb(int a,int b){
	f[fd(b)]=fd(a);
}

int main()
{
	while(true){
		int ans=0;
		int n,m;
		cin>>n;
		if(n==0){
			break;
		}
		cin>>m;
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
		int a,b;
		for(int i=1;i<=m;++i){
			cin>>a>>b;
			if(fd(a)!=fd(b)){
				hb(a,b);
			}
		}
		for(int i=1;i<=n;++i){
			if(fd(a)!=fd(i)){
				hb(a,i);
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}