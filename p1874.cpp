#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 45
#define M 100005
using namespace std;

int num[N][N];
int dp[N][M];

int main() {
	memset(dp,0x3f,sizeof(dp));
    string s;
    int n;
    cin>>s>>n;
    int len=s.length();
    for(int i=1;i<=len;i++){
        for (int j=i;j<=len;j++){
            num[i][j]=num[i][j-1]*10+(s[j-1]-'0');
            if(num[i][j]>n) num[i][j]=n+1;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=len;i++){
        for(int j=0;j<=n;j++){
            if(dp[i-1][j]==inf) continue;
            int cur=0;
            for(int k=i;k<=len;k++){
                cur=cur*10+(s[k-1]-'0');
                if(cur>n) break;
                if(j+cur<=n){
                    dp[k][j+cur]=min(dp[k][j+cur],dp[i-1][j]+1);
                }
            }
        }
    }
    int ans=dp[len][n]-1;
    if(ans>=len){
        cout<<-1<<endl;
    }
	else{
        cout<<ans<<endl;
    }
    return 0;
}