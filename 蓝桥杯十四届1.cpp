#include <bits/stdc++.h>
using namespace std;

vector<int> e[10];
int len[10];
int arr[105];
int ans;

int main()
{
  int num;
  for(int i=1;i<=100;++i){
    cin>>num;
    e[num].push_back(i);
    arr[i]=num;
  }
  for(int i=0;i<=9;++i){
    len[i]=e[i].size();
  }
  for(int i=0;i<len[2];++i){
    for(int j=0;j<len[0];++j){
      if(e[2][i]>e[0][j]) continue;
      for(int k=0;k<len[2];++k){
        if(e[0][j]>e[2][k]) continue;
        for(int l=0;l<len[3];++l){
          if(e[2][k]>e[3][l]) continue;
          for(int a=e[3][l]+1;a<=100;++a){
            if(arr[a]>1) continue;
            for(int b=a+1;b<=100;++b){
              for(int c=b+1;c<=100;++c){
                for(int d=c+1;d<=100;++d){
                  int m=arr[a]*10+arr[b];
                  int day=arr[c]*10+arr[d];
                  if(m==2&&day>28) continue;
                  if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&day>31) continue;
                  if((m==4||m==6||m==9||m==11)&&day>31) continue;
                  ans++;
                }           
              }
            }
          }
        }
      }
    }
  }
  cout<<ans;
  return 0;
}