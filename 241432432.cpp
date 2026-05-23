#include<bits/stdc++.h>
#define N 10005
using namespace std;

struct node{
    int v,p;
};

int n,m;
vector<node> e[N];
int vis[N];

int main()
{
    cin>>n>>m;
    int id1,id2,p;
    for(int i=1;i<=m;++i){
        cin>>id1>>id2>>p;
        e[id1].push_back({id2,p});
    }
    int k;
    cin>>k;
    int x;
    while(k--){
        cin>>x;
        vector<int> ans;
        memset(vis,0,sizeof(vis));
        while(1){
            ans.push_back(x);
            vis[x]=1;
            int maxn=0;
			if(e[x].empty()) break;
            for(auto z:e[x]){
                if(vis[z.v]) continue;
                if(maxn<z.p){
                    x=z.v;
                    maxn=z.p;
                }
                else if(maxn==z.p){
                    if(x>z.v){
                        x=z.v;
                    }
                }
            }
        }
        int len=ans.size();
        for(int i=0;i<len-1;++i){
            cout<<ans[i]<<"->";
        }
        cout<<ans[len-1]<<endl;
    }
    
    return 0;
}