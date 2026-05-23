#include<bits/stdc++.h>
#define N 10005
#define M 100005
using namespace std;

struct edge{
	int u,v;
};
vector<edge> e;
vector<int> h[N];
int dfn[N],low[N],tot,cnt;
struct bridge{
	int x,y;
}bri[M];

void add(int a,int b){
	e.push_back({a,b});
	h[a].push_back(e.size()-1);
}

void tarjan(int x,int in_edg){
	dfn[x]=low[x]=++tot;
	for(int i=0;i<h[x].size();++i){
		int j=h[x][i];
		int y=e[j].v;
		if(!dfn[y]){
			tarjan(y,j);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]){
				bri[++cnt]={x,y};
			}
		}
		else if(j!=(in_edg^1)){
			low[x]=min(low[x],dfn[y]);
		}
	}
}

int main()
{
	
	return 0;
}