#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a,b,op;
int f[205];

int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

void unite(int a,int b){
    int fa=find(a);
    int fb=find(b);
    f[fa]=fb;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n*2;++i){
        f[i]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>a>>b>>op;
        if(op==1){
            unite(a,b);
            unite(a+n,b+n);
        }
        if(op==-1){
            unite(a+n,b);
            unite(a,b+n);
        }
    }
    for(int i=1;i<=k;++i){
        cin>>a>>b;
        int x1=find(a);
        int x2=find(b);
        int y1=find(a+n);
        int y2=find(b+n);
        bool friends=(x1==x2);
        bool army=(x1==y2||x2==y1);
        if(friends&&!army){
            cout<<"No problem"<<endl;
        }
        else if(!friends&&!army){
            cout<<"OK"<<endl;
        }
        else if(friends &&army){
            cout<<"OK but..."<<endl;
        }
        else if(army){
            cout<<"No way"<<endl;
        }
    }
    return 0;
}