#include<bits/stdc++.h>
using namespace std;

vector<int>prime;
bool isp[100010];
int f[100010];
int p;

void zhi(int x){
	for(int i=2;i<=x;++i){
		if(!isp[i]){
			prime.push_back(i);
		}
		for(int j=0;j<prime.size()&&i*prime[j]<=x;++j){
			isp[i*prime[j]]=true;
			if(i%prime[j]==0){
				break;
			}
		}
	}
}

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
	int a,b;
	cin>>a>>b>>p;
	zhi(b+5);
	for(int i=a;i<=b;++i){
		f[i]=i;
	}
	for(int q:prime){
		if(q<p) continue;
		int ff=-1;
		for(int j=q;j<=b;j+=q){
			if(j<a)continue;
			if(ff==-1){
				ff=j;
			}
			else{
				hb(ff,j);
			}
		}
	}
	int ans=0;
	for(int i=a;i<=b;++i){
		if(fd(i)==i){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}