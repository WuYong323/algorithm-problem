#include<bits/stdc++.h> 
#define N 1005
#define ll long long
using namespace std;

const int mod=1e9+7;

int n,m;
int a[N][N];
int b[N][N];
int s[N][N];

ll ans;

int main( )
{
    cin>>n>>m;
    int num=n-m+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            cin>>b[i][j];
        }
    }

    for(int p=0;p<32;++p){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int val=(a[i][j]>>p)&1;
                s[i][j]=s[i-1][j]+s[i][j-1]+val-s[i-1][j-1];
            }
        }
        ll bit=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                int b_val=(b[i][j]>>p)&1;
                int r1=i;
                int c1=j;
                int r2=i+num-1;
                int c2=j+num-1;
                int ones=s[r2][c2]-s[r1-1][c2]-s[r2][c1-1]+s[r1-1][c1-1];

                if(b_val==0){
                    bit+=ones;
                }
                else{
                    bit+=(num*num-ones);
                }
            }
        }
        ll power_2=(1LL<<p)%mod;
        ans=(ans+bit%mod*power_2)%mod;
    }
    cout<<ans;
    return 0;
}