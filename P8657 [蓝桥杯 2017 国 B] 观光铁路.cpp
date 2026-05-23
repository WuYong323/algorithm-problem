#include<bits/stdc++.h>
using namespace std;

const int N=25;
const double eps=1e-9;

int n,m;
vector<int> e[N];
int de[N];
double a[N*N][N*N];
int idx;

void gauss(int n){
	for(int i=0;i<n;++i){
		int r=i;
		for(int j=i+1;j<n;++j){
			if(fabs(a[j][i])>fabs(a[r][i])) r=j;
		}
		if(fabs(a[r][i])<eps) continue;
		if(r!=i) swap(a[i],a[r]);
		double div=a[i][i];
		for(int j=i;j<=n;++j) a[i][j]/=div;
		for(int j=0;j<n;++j){
			if(j==i) continue;
			double factor=a[j][i];
			for(int k=i;k<=n;++k){
				a[j][k]-=factor*a[i][k];
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		--u;
		--v;
		e[u].push_back(v);
		e[v].push_back(u);
		de[u]++;
		de[v]++;
	}
	for(int s=0;s<n;++s){
		map<pair<int,int>,int> state_id;
		idx=0;
		for(int u=0;u<n;++u){
			for(int v:e[u]){
				if(state_id.find({u,v})==state_id.end()){
					state_id[{u,v}]=idx++;
				}
			}
		}
		memset(a,0,sizeof(a));
		for(auto &p:state_id){
			int u=p.first.first;
			int v=p.first.second;
			int id=p.second;
			if(u==s){
				a[id][id]=1.0;
				a[id][idx]=1.0;
				for(int w:e[u]){
					int nid=state_id[{w,u}];
					a[id][nid]-=1.0/de[u];
				}
			}
			else {
				a[id][id]=1.0;
				a[id][idx]=1.0;
				for(int w:e[u]){
					if(w==v) continue;
					int nid=state_id[{w,u}];
					a[id][nid]-=1.0/(de[u]-1);
				}
			}
		}
		gauss(idx);
		double ans=1.0;
		for(int w:e[s]){
			int nid=state_id[{w,s}];
			ans+=1.0/de[s]*a[nid][idx];
		}
		printf("%.12f\n",ans);
	}
	return 0;
}