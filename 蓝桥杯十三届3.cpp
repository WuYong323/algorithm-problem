#include <bits/stdc++.h>
#define N 10005
using namespace std;

int n;
int v[N],x[N];
int maxn,mine=1e9;

int main()
{
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>v[i]>>x[i];
    mine=min(mine,v[i]/x[i]);
  }
  for(int i=maxn;;++i){
    int f=1;
    for(int j=1;j<=n;++j){
      if(v[j]/maxn!=x[i]){
        f=0;
        break;
      }
    }
    if(f) maxn=i;
    else break;
  }
  for(int i=mine;;--i){
    int f=1;
    for(int j=1;j<=n;++j){
      if(v[j]/mine!=x[i]){
        f=0;
        break;
      }
    }
    if(f) mine=i;
    else break;
  }
  cout<<mine<<" "<<maxn;
  return 0;
}