#include<bits/stdc++.h>
#define N 20005
#define M 100005
using namespace std;

struct edge{
	int u,v,w;
}e[M];

int n,m,k;
int fa[N];
vector<int> vect;

bool comp1(edge a,edge b){
	return a.w>b.w;
}

bool comp2(edge a,edge b){
	return a.w<b.w;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void init(){
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
}

void check(){
	int t=find(1);
	for(int i=2;i<=n;++i){
		int f=find(i);
		if(f!=t){
			cout<<"no solution";
			exit(0);
		}
	}
}

int main()
{
	cin>>n>>m>>k;
	int u,v,c;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>c;
		e[i]={u,v,c};
	}
	init();
	sort(e+1,e+1+m,comp1);
	int all=0;
	for(int i=1;i<=m;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			if(e[i].w==0){
				all++;
				e[i].w=-1;
			}
		}
	}
	if(all>k){
		cout<<"no solution";
		return 0;
	}
	check();
	init();
	sort(e+1,e+1+m,comp2);
	for(int i=1;i<=m;++i){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			if(e[i].w==0&&all<k){
				fa[x]=y;
				vect.push_back(i);
				all++;
			}
			else if(e[i].w==1||e[i].w==-1){
				fa[x]=y;
				if(e[i].w==-1) e[i].w=0;
				vect.push_back(i);
			}
		}
	}
	if(all<k){
		cout<<"no solution";
		return 0;
	}
	check();
	for(int p:vect){
		cout<<e[p].u<<" "<<e[p].v<<" "<<e[p].w<<endl;
	}
	return 0;
}