#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,a[N],b[N],pos[N],lis[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
        b[i]=pos[b[i]];
    }
    int len=0;
    for (int i=1;i<=n;i++){
        int x=b[i];
        int p=lower_bound(lis+1,lis+len+1,x)-lis;
        lis[p]=x;
        if(p>len) len=p;
    }
    cout<<len<<endl;
    return 0;
}