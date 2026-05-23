#include<bits/stdc++.h>
using namespace std;

struct people{
    string ming;
    string xin;
    int gender;
}peo[100005];
int n,m;

map<string,int> name_id;
int fa[100005];
vector<int> children[100005];
int depth[100005];

void dfs(int u,int d){
    depth[u]=d;
    for(int v:children[u]){
        dfs(v,d+1);
    }
}

bool lca(int x,int y,int gen){
    if(gen>=5) return 0;
    if(x==y) return 1;
    if(depth[x]==depth[y]) return lca(fa[x],fa[y],gen+1);
    if(depth[x]>depth[y]) return lca(fa[x],y,gen+1);
    return lca(x,fa[y],gen+1);
}

int main()
{
    cin>>n;
    string xin,ming;
    for(int i=1;i<=n;++i){
        cin>>ming;
        name_id[ming]=i;
        cin>>xin;
        int t=xin.size();
        if(t>=4&&xin.substr(t-4)=="sson") {
            peo[i].gender=1;
            xin=xin.substr(0,t-4);
        }
        else if(t>=7&&xin.substr(t-7)=="sdottir"){
            peo[i].gender=-1;
            xin=xin.substr(0,t-7);
        }
        else if(xin[t-1]=='m'){
            peo[i].gender=1;
            xin=xin.substr(0,t-1);
        }
        else if(xin[t-1]=='f'){
            peo[i].gender=-1;
            xin=xin.substr(0,t-1);
        }
        peo[i].ming=ming;
        peo[i].xin=xin;
    }
    for(int i=1;i<=n;++i){
        int x,y;
        x=name_id[peo[i].ming];
        y=name_id[peo[i].xin];
        children[x].push_back(y);
        fa[y]=x;
    }
    dfs(1,0);
    cin>>m;
    string ming1,xin1,ming2,xin2;
    int a,b;
    for(int i=1;i<=m;++i){
        cin>>ming1>>xin1>>ming2>>xin2;
        a=name_id[ming1];
        b=name_id[ming2];
        if(!a||!b) {
            cout<<"NA"<<endl;
            continue;
        }
        if(peo[a].gender==peo[b].gender) {
            cout<<"Whatever"<<endl;
            continue;
        }
        if(lca(a,b,1)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}