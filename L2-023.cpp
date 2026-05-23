#include<bits/stdc++.h>
#define N 505
using namespace std;

int num,edge,k,n;
vector<int> e[N];
int color[N];
int vis[N];
bool flage;

void dfs(int s){
    vis[s]=1;
    for(int x:e[s]){
        if(!vis[x]){
            if(color[s]==color[x]){
                flage=1;
            }
            dfs(x);
        }
    }
}

int main()
{
    cin>>num>>edge>>k;
    int u,v;
    for(int i=1;i<=edge;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>n;
    for(int k=1;k<=n;++k){
        int co;
        memset(vis,0,sizeof(vis));
        flage=0;
        for(int i=1;i<=num;++i){
            cin>>co;
            color[i]=co;
        }
        dfs(1);
        if(!flage)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}