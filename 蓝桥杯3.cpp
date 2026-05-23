#include <iostream>
#define N 105
using namespace std;

int n;
int a[N];
int sum;
int ans;
int vis[N];

void dfs(int st){
  int num=1;
  for(int i=st;;++i){
    if(i%n==0){
      i=n;
    }
    else i%=n;
    if(vis[i]) continue;
    if(a[i]==num){
      num=1;
      sum+=num;
      vis[num]=1;
      continue;
    }
    num++;
    if(num>n){
      break;
    }
  }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  for(int i=1;i<=n;++i){
  	memset(vis,0,sizeof(vis));
    sum=0;
    dfs(i);
    ans=max(ans,sum);
  }
  cout<<ans;
  return 0;
}