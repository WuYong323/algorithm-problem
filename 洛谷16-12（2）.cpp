#include<bits/stdc++.h>
using namespace std;

const int MAXN=200020;
int f[MAXN];

unordered_map<int,int> mp;
int idx = 0;

int gt(int x) {
    if (mp.count(x)) return mp[x];
    return mp[x]=++idx;
}

int fd(int x) {
    if (f[x]!=x) f[x]=fd(f[x]);
    return f[x];
}

void hb(int a, int b) {
    f[fd(b)]=fd(a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        mp.clear();
        idx=0;
        for(int i=1;i<=MAXN;i++){
            f[i] = i;
        }
        vector<tuple<int, int, int>> q;
        for (int i=1;i<=n;i++) {
            int a,b,e;
            cin>>a>>b>>e;
            a=gt(a);
            b=gt(b);
            q.push_back({a,b,e});
        }
        for(auto [a,b,e]:q) {
            if(e==1){
                hb(a,b);
            }
        }
        bool valid=true;
        for(auto [a,b,e]:q) {
            if(e==0&&fd(a)==fd(b)) {
                valid=false;
                break;
            }
        }
        cout<<(valid?"YES":"NO")<<endl;
    }
    return 0;
}