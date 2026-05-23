#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int id[1005];

bool check(){
    int len=1;
    stack<int> s;
    for(int i=1;i<=n;){
        if(len!=id[i]) {
            s.push(id[i]);
            i++;
            if(s.size()>m) return false;
        }
        else {
            len++;
            while(len!=n+1&&len==s.top()) {
                len++;
                s.pop();
            }
            i++;
        }
    }
    if(len-1==n) return true;
    while(1){
        if(s.top()==len){
            s.pop();
            len++;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i){
    	for(int j=1;j<=n;++j){
    		cin>>id[j];
		}
        if(check()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}