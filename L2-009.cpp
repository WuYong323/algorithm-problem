#include<bits/stdc++.h>
#define N 10005
using namespace std;

struct peo{
    int id;
    double val;
}people[N];
int n;
int k,id,p;

bool comp(peo a,peo b){
    if(a.val!=b.val){
        return a.val>b.val;
    }
    else{
        return a.id<b.id;
    }
    
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>id>>p;
            people[i].val-=1.0*p/100;
            people[id].val+=1.0*p/100;
        }
    }
    for(int i=1;i<=n;++i){
        people[i].id=i;
    }
    sort(people+1,people+n+1,comp);
    for(int i=1;i<=n;++i){
        printf("%d %.2f\n",people[i].id,people[i].val);
    }
    return 0;
}