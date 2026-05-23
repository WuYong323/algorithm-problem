#include<bits/stdc++.h>
using namespace std;

int m=200020;
int f[400040];

int fd(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fd(f[x]);
}

void hb(int a,int b){
	f[fd(b)]=fd(a);
}

bool same(int a,int b){
	return fd(a)==fd(b);
}

int main()
{
	int t;
	cin>>t;
	for(int g=1;g<=t;++g){
		int n;
		cin>>n;
		bool bo=true;
		for(int i=1;i<=2*m;++i){
			f[i]=i;
		}
		for(int l=1;l<=n;l++){
			int i,j,e;
			cin>>i>>j>>e;
			if(!bo) continue;
			if(e==1){
				if(same(i,j+m)||same(i+m,j)){
					bo=false;
				}
				else{
					hb(i,j);
					hb(i+m,j+m);
				}
			}
			else if(e==0){
				if(same(i,j)){
					bo=false;
				}
				else{
					hb(i,j+m);
					hb(i+m,j);
				}
			}
		}
		if(bo) cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}