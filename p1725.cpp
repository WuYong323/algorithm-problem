#include<bits/stdc++.h>
using namespace std;

int n,l,r;
int w[200005];
int ans=0x8f8f8f8f;
int dp[200005];
int q[200005];
int head=0,tail=-1;

int main()
{
	cin>>n>>l>>r;
	for(int i=0;i<=n;++i){
		cin>>w[i];
	}
	memset(dp,0x8f,sizeof(dp));
	dp[0]=0;
	for(int i=l;i<=n;++i){
		int cand=i-l;
        while(head<=tail&&dp[q[tail]]<=dp[cand]){
            tail--;
        }
        q[++tail]=cand;
        while(head<=tail&&q[head]<i-r){
            head++;
        }
        if(head<=tail) {
            dp[i]=dp[q[head]]+w[i];
        }
	}
	for(int i=n-r+1;i<=n;++i){
		if(i>=0) ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}