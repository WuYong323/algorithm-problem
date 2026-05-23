#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

const int mod=1e9+7;

int n;
int a[N];
int A1[N],A2[N];
int ans;

signed main()
{
  cin>>n;
  A1[0]=1;
  A2[0]=1;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    A2[i]=A2[i-1]*2%mod;
    A1[i]=A1[i-1]*3%mod;
  }
  for(int i=2;i<=n;++i){
    a[i]=a[i]^a[i-1];
  }
  int len=0;
  for(int i=2;i<=n;++i){
    ans+=(a[i]*A2[n-i])%mod;
    ans%=mod;
    len+=A2[n-i];
    len%=mod;
  }
  ans+=((A1[n-1]-len)%mod)*a[1];
  ans%=mod;
  cout<<ans;
  return 0;
}