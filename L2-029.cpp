#include<bits/stdc++.h>
using namespace std;

int a,b;
int vis[10005];
vector<pair<int,int>> v;

int zhishu(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int check(int x){
    set<int> s;
    while(true){
        int sum=0;
        while(x>0){
            int t=x%10;
            sum+=t*t;
            x/=10;
        }
        if(sum==1) return s.size()+1;
        if(s.count(sum)) return 0;
        s.insert(sum);
        if(sum>=a&&sum<=b) vis[sum]=1;
        x=sum;
    }
}

int main()
{
    cin>>a>>b;
    for(int i=a;i<=b;++i){
        if(!vis[i]){
            int t=check(i);
            if(t){
                if(zhishu(i)){
                    v.push_back({i,t*2});
                }
                else{
                    v.push_back({i,t});
                }
            }
        }
    }
    for(auto x:v){
        if(!vis[x.first]){
            printf("%d %d\n",x.first,x.second);
        }
    }
    return 0;
}