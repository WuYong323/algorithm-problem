#include<bits/stdc++.h>
using namespace std;

struct item {
    int v,p,q;
};

int main() {
    int N, m;
    cin >> N >> m;
    vector<item> items(m + 1);
    vector<vector<int>> attach(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> items[i].v >> items[i].p >> items[i].q;
        if (items[i].q > 0) {
            attach[items[i].q].push_back(i);
        }
    }
    vector<int> dp(N+1,0);
    for (int i=1;i<=m;i++) {
        if (items[i].q!=0) continue;
        vector<pair<int,int>> choices;
        int v0=items[i].v,p0=items[i].p;
        choices.push_back({v0,v0*p0});
        int cnt=attach[i].size();
        if (cnt>=1) {
            int v1=items[attach[i][0]].v,p1=items[attach[i][0]].p;
            choices.push_back({v0+v1,v0*p0+v1*p1});
            if (cnt>=2){
                int v2=items[attach[i][1]].v,p2=items[attach[i][1]].p;
                choices.push_back({v0+v2,v0*p0+v2*p2});
                choices.push_back({v0+v1+v2,v0*p0+v1*p1+v2*p2});
            }
        }
        for (int j=N;j>=0;j--) {
            for (auto &choice:choices) {
                int cost=choice.first,val=choice.second;
                if (j>=cost){
                    dp[j]=max(dp[j],dp[j-cost]+val);
                }
            }
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}