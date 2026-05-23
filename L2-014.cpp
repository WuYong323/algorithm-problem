#include<bits/stdc++.h>
using namespace std;

int n;
int entrance[100005];
int vis[100005];

int main()
{
    cin>>n;
    int num;
    for(int i=1;i<=n;++i){
        cin>>num;
        entrance[i]=num;
    }
    int ans=0;
    num=0;
    while(true){
        bool flage=1;
        for(int i=n;i>=1;--i){
            if(!vis[i]){
                flage=0;
                if(num==0) num=entrance[i],vis[i]=1;
                if(entrance[i]<num) vis[i]=1,num=entrance[i];
            }
        }
        ans++;
        if(flage) break;
    }
    cout<<ans;
    return 0;
}