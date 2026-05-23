#include<bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;

struct edge{
	int u,v;
	ll w;
	bool operator < (const edge &t) const{
		return w<t.w;
	}
}e[N*N];

int n;
int x[N],y[N];
int c[N],k[N];
int len;
int fa[N];
vector<int> vect;
vector<pair<int,int>> ed;
int ans;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void krucal(){
	for(int i=0;i<=n;++i) fa[i]=i;
	sort(e+1,e+1+len);
	for(int i=1;i<=len;++i){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].w;
			if(e[i].u==0){
				vect.push_back(e[i].v);
			}
			else{
				ed.push_back({e[i].u,e[i].v});
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		e[++len].u=0;
		e[len].v=i;
		e[len].w=c[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			e[++len].u=i;
			e[len].v=j;
			e[len].w=1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	}
	krucal();
	cout<<ans<<endl;
	cout<<vect.size()<<endl;
	for(int x:vect){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<ed.size();
	for(auto p:ed){
		cout<<p.first<<" "<<p.second;
	}
	return 0;
}