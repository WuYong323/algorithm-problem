#include<bits/stdc++.h>
#define N 1005
using namespace std;

const double ESP=1e-8;

struct people{
    int id;
    double val;
};

int n,m;
int gender[N];
vector<int> e[N];
people A[1005],B[1005];
vector<int,double> ansa,ansb;

bool comp(people a,people b){
    if(a.val!=b.val){
        return a.val>b.val;
    }
    else{
        return a.id<b.id;
    }
}

int main()
{
    cin>>n>>m;
    int num;
    string id;
    for(int i=1;i<=m;++i){
        cin>>num;
        for(int j=1;j<=num;++i){
            cin>>id;
            if(id=="-0") gender[0]=-1;
            if(id=="0") gender[0]=1;
            int p=stoi(id);
            if(p>0) gender[p]=1;
            else if(p<0) gender[abs(p)]=-1;
            e[i].push_back(abs(p));
        }
    }
    int a,b;
    cin>>a,b;
    a=abs(a);
    b=abs(b);
    for(int i=1;i<=m;++i){
        int t=e[i].size();
        if(find(e[i].begin(),e[i].end(),a)!=e[i].end()){
            for(int x:e[i]){
                if(x!=a&&gender[a]!=gender[x]) {
                    A[x].val+=1.0/t;
                    A[x].id=id;
                }
            }
        }
        if(find(e[i].begin(),e[i].end(),b)!=e[i].end()){
            for(int x:e[i]){
                if(x!=b&&gender[b]!=gender[x]){
                    B[x].val+=1.0/t;
                    B[x].id=id;
                }
            }
        }
    }
    sort(A,A+n,comp);
    sort(B,B+n,comp);
    bool flage1=0,flage2=0;
    for(int i=0;i<n;++i){
        ansa.push_back({a,gender[A[i].id]*A[i].id});
        if(A[i].val-A[i+1].val>ESP) {
            flage1=1;
            break;
        }
        ansa.push_back({b,gender[B[i].id]*B[i].id});
        if(B[i].val-B[i+1].val>ESP) {
            flage2=1;
            break;
        }
    }
    if(flage1&&flage2){
        printf("%d %d",a*gender[a],b*gender[b]);
    }
    else{
        for(auto q:ansa){
            printf("%d %d\n",q.first,q.second);
        }
        for(auto q:ansb){
            printf("%d %d\n",q.first,q.second);
        }
    }
    return 0;
}