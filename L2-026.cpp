#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n;
vector<int> e[N];
int vis[N];
int deep;
int ans;

void dfs(int s,int depth){
    vis[s]=1;
    for(int x:e[s]){
        if(!vis[x]){
            dfs(x,depth+1);
            if(deep<depth){
                ans=s;
                deep=depth;
            }
        }
    }
}

int main()
{
    cin>>n;
    int num,head;
    for(int i=1;i<=n;++i){
        cin>>num;
        if(num!=-1){
            e[num].push_back(i);
        }
        else{
            head=i;
        }
    }
    dfs(head,0);
    cout<<deep<<endl;
    cout<<e[ans][0];
    int t=e[ans].size();
    for(int i=1;i<t;++i){
        cout<<" "<<e[ans][i];
    }
    return 0;
}