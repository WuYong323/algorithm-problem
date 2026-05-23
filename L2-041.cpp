#include<bits/stdc++.h>
using namespace std;

int n,m,k;
deque<int> q;
vector<int> v;
stack<int> s;

int main()
{
    cin>>n>>m>>k;
    int id;
    for(int i=1;i<=n;++i){
        cin>>id;
        q.push_back(id);
    }
    while(!q.empty()||!s.empty()){
        if(!s.empty()&&(v.empty()||s.top()<=v.back())){
            id=s.top();
            s.pop();
            v.push_back(id);
        }
        else if(!q.empty()){
            id=q.front();
            q.pop_front();
            if(v.empty()||id<=v.back()){
                v.push_back(id);
            }
            else{
                if((int)s.size()==m) {
                    int t=v.size();
                    cout<<v[0];
                    for(int i=1;i<t;++i){
                        cout<<" "<<v[i];
                    }
                    cout<<endl;
                    v.clear();
                    q.push_front(id);
                }
                else{
                    s.push(id);
                }
            }
        }
        else if(q.empty()){
            int t=v.size();
            cout<<v[0];
            for(int i=1;i<t;++i){
                cout<<" "<<v[i];
            }
            cout<<endl;
            v.clear();
        }
        if((int)v.size()==k) {
            int t=v.size();
            cout<<v[0];
            for(int i=1;i<t;++i){
                cout<<" "<<v[i];
            }
            cout<<endl;
            v.clear();
        }
    }
    int t=v.size();
    cout<<v[0];
    for(int i=1;i<t;++i){
        cout<<" "<<v[i];
    }
    return 0;
}