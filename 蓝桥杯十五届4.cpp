#include <bits/stdc++.h>
using namespace std;

int n;
string d;
int num[1050];
int len;
int point;

void mul(){
  while(n--){
    int x=0;
    for(int i=1;i<=len;++i){
      num[i]=num[i]*2+x;
      x=num[i]/10;
      num[i]%=10;
    }
    while(x!=0){
      num[++len]=x%10;
	  x/=10;
    }
  }
}

int main()
{
  cin>>n;
  cin>>d;
  int t=d.size();
  for(int i=t-1;i>=0;--i){
    if(d[i]!='.') num[++len]=d[i]-'0';
    else point=len;
  }
  mul();
  for(int i=1;i<=point;++i){
    if(num[i]>=5) num[i+1]++;
  }
  for(int i=len;i>point;--i){
    cout<<num[i];
  }
  return 0;
}