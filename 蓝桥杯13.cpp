#include <bits/stdc++.h>
#define N 10005
using namespace std;

struct picture{
  int w,h;
}p[N];

int m,n;
int ans=1e9;

int fun(int idx){
  int rew=0;
  int high=0;
  int hh=0;
  int t=m;
  for(int i=1;i<=n;++i){
    if(i==idx) continue;
    if(p[i].w<=t){
      t-=p[i].w;
      hh=max(hh,p[i].h);
    }
    else{
      double r=p[i].w/(double)t;
      int h=(p[i].h+r-1)/r;
      hh=max(hh,h);
      high+=hh;
      hh=0;
    }
  }
  return high;
}

int main()
{
  cin>>m>>n;
  for(int i=1;i<=n;++i){
    cin>>p[i].w>>p[i].h;
  }
  for(int i=1;i=n;++i){
    ans=min(ans,fun(i));
  }
  cout<<ans;
  return 0;
}