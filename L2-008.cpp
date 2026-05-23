#include<bits/stdc++.h>
using namespace std;

char a[1005],s[1005];
int d[1005];
int ans;

void get_d(char *s,int n){
    d[1]=1;
    for(int i=2,l,r=1;i<=n;++i){
        if(i<=r) d[i]=min(d[r-i+l],r-i+1);
        while(s[i+d[i]]==s[i-d[i]]) d[i]++;
        if(i+d[i]-1>r) l=i-d[i]+1,r=i+d[i]-1;
    }
}

int main()
{
    scanf("%[^\n]s",a+1);
    int n=strlen(a+1);
    int k=0;
    s[0]='$';
    s[++k]='#';
    for(int i=1;i<=n;++i){
        s[++k]=a[i];
        s[++k]='#';
    }
    n=k;
    get_d(s,n);
    for(int i=2;i<=n;i+=2){
        ans=max(ans,d[i]);
    }
    ans=ans*2-1;
    ans=(ans-1)/2;
    cout<<ans;
    return 0;
}