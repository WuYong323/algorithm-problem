#include<bits/stdc++.h>
using namespace std;

int n,m,s;
queue<char> q[105];
stack<char> kuang;
vector<char> ans;

int main()
{
    cin>>n>>m>>s;
    char thing;
    getchar();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            thing=getchar();
            q[i].push(thing);
        }
        getchar();
    }
    int op=0;
    while(1){
        cin>>op;
        if(op==-1) break;
        if(op!=0) {
            if(!q[op].empty()) {
                thing=q[op].front();
                q[op].pop();
                if(kuang.size()<s){
                    kuang.push(thing);
                }
                else{
                    char yu=kuang.top();
                    kuang.pop();
                    kuang.push(thing);
                    ans.push_back(yu);
                }
            }
        }
        else{
            if(!kuang.empty()){
                thing=kuang.top();
                kuang.pop();
                ans.push_back(thing);
            }
        }
    }
    for(char x:ans){
        cout<<x;
    }
    return 0;
}