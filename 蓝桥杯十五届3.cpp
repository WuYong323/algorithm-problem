#include <bits/stdc++.h>
using namespace std;

int n;
int a[10];
int wei[10];
int ans;

int main()
{
  cin>>n;
  for(int i=1;i<=7;++i){
    a[i]=pow(5,(i+1)/2)*pow(4,i/2);
  }
  a[0]=1;
  int len=0;
  while(n>0){
    wei[++len]=n%10;
    n/=10;
  }
  for(int i=1;i<len;++i){
    ans+=a[i];
  }
  for(int j=len;j>=1;--j){
    for(int i=1;i<wei[j];++i){
     if(i%2==j%2){
       ans+=a[j-1];
     }
    }
  }
  cout<<ans;
  return 0;
}