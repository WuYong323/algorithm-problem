#include<bits/stdc++.h> 
#define N 300005
#define ll long long
#define mod 10007
using namespace std;

int a[N];


int main( )
{
    int n,m;
    cin>>n>>m; 
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l,r;
    ll ans=0;
    while(m--){
        cin>>l>>r;
        int L,R;
        L=lower_bound(a+1,a+1+n,l)-a;
        if(r<=a[n]) R=lower_bound(a+1,a+1+n,r)-a;
        else R=n;
        if(a[R]>r) R--;
        ans=(ans+n-R+L-1)%mod;
    }
    cout<<ans;
    return 0;
}