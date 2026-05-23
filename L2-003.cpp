#include<bits/stdc++.h>
using namespace std;

struct node{
    int num;
    int w;
    double price;
}nd[1005];

int n,d;
int sum;
double ans;
bool comp(node a,node b){
    return a.price>b.price;
}


int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>nd[i].num;
    }
    for(int i=1;i<=n;++i){
        cin>>nd[i].w;
    }
    for(int i=1;i<=n;++i){
        nd[i].price=1.0*nd[i].w/nd[i].num;
    }
    sort(nd+1,nd+1+n,comp);
    for(int i=1;i<=n;++i){
        if(sum+nd[i].num<=d){
            sum+=nd[i].num;
            ans+=nd[i].w;
        }
        else{
            ans+=nd[i].price*(d-sum);
            break;
        }
    }
    cout<<ans;
    return 0;
}