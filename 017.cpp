#include<bits/stdc++.h>
using namespace std;

char num[55];
int len;
int t;

int main()
{
    while(cin>>num[++len]);
    for(int i=1;i<=len;++i){
        if(num[i]=='2'){
            t++;
        }
    }
    double ans=1;
    len-=2;
    if(num[len]%2==0) ans*=2;
    if(num[1]=='-'){
        ans*=1.5;
        len--;
    }
    ans*=100;
    ans*=(double)t/len;
    printf("%.2f%",ans);
    return 0;
}