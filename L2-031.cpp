#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,k;
int id;
vector<int> e[N];
bool ischild[N];
int deep=0,ans=1;

void dfs(int s,int depth){
    if(deep<depth){
        deep=depth;
        ans=s;
    }
    for(int x:e[s]){
        dfs(x,depth+1);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>id;
            e[i].push_back(id);
            ischild[id]=1;
        }
    }
    for(int i=1;i<=n;++i){
        if(!ischild[i]){
            dfs(i,1);
        }
    }
    cout<<ans;
    return 0;
}