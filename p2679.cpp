#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n,m,k;
string a,b;
int f[2][205][205];
int g[2][205][205];

int main() 
{
    cin>>n>>m>>k;
    cin>>a>>b;
    g[0][0][0]=1;
    for(int i=1;i<=n;++i){
        int cur=i&1,pre=cur^1;
        memset(f[cur],0,sizeof(f[cur]));
        memset(g[cur],0,sizeof(g[cur]));
        g[cur][0][0]=1;
        for(int j=1;j<=m;++j){
            for(int p=1;p<=k;++p){
                if(a[i-1]==b[j-1]){
                    f[cur][j][p]=(f[pre][j-1][p]+g[pre][j-1][p-1])%MOD;
                } 
				else{
                    f[cur][j][p]=0;
                }
                g[cur][j][p]=(g[pre][j][p]+f[cur][j][p])%MOD;
            }
        }
    }
    cout<<g[n&1][m][k];
    return 0;
}