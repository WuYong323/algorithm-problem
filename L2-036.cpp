#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;


int n,m,k;
int f[205][205];
int plane[205];
int ans=inf;
int idx;
int all;

int main()
{
    cin>>n>>m;
    int u,v,w;
    memset(f,0x7f,sizeof(f));
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        f[u][v]=w;
        f[v][u]=w;
    }
    cin>>k;
    int num,id;
    for(int i=1;i<=k;++i){
        cin>>num;
        set<int> s;
        bool flage=0;
        for(int j=1;j<=num;++j){
            cin>>id;
            plane[j]=id;
            if(s.count(id)) {
                flage=1;
            }
            s.insert(id);
        }
        if(f[0][plane[1]]!=0x7f7f7f7f&&f[plane[num]][0]!=0x7f7f7f7f&&!flage&&num==n){
            int sum=0;
            id=0;
            for(int j=1;j<=num;++j){
                sum+=f[id][plane[j]];
                id=plane[j];
            }
            sum+=f[plane[num]][0];
            if(ans>sum){
                ans=sum;
                idx=i;
            }
            all++;
        }
    }
    cout<<all<<endl;
    cout<<idx<<" "<<ans;
    return 0;
}