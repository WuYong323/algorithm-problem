#include<bits/stdc++.h>
#define N 150005
using namespace std;

int n,m;
int a[N];
int dp[400][400];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	char cmd;
	int x,y;
	for(int i=1;i*i<=n;++i){
		for(int j=0;j<i;++j){
			int ans=0;
			int t=0;
			while(t*i+j<=n){
				ans+=a[t*i+j];
				t++;
			}
			dp[i][j]=ans;
		}
		
	}
	for(int i=1;i<=m;++i){
		cin>>cmd>>x>>y;
		if(cmd=='A'){
			if(x*x<=n){
				cout<<dp[x][y]<<endl;;
			}
			else{
				int ans=0;
				int t=0;
				while(y+t*x<=n){
					ans+=a[y+t*x];
					t++;
				}
				cout<<ans<<endl;
			}
		}
		else{
			for(int i=1;i*i<n;++i){
				dp[i][x%i]=dp[i][x%i]-a[x]+y;
			}
			a[x]=y;
		}
	}
	return 0;
}