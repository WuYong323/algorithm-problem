#include<bits/stdc++.h>
using namespace std;

int t,n;
int dp[1005];

int main()
{
	int h1,m1,h2,m2;
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	t=(h2-h1)*60+m2-m1;
	cin>>n;
	int w,c,p;
	for(int i=1;i<=n;++i){
		cin>>w>>c>>p;
		if(p==0){
			for(int j=w;j<=t;++j){
				dp[j]=max(dp[j],dp[j-w]+c);
			}
		}
		else {
			int k=1;
			while(k<=p){
				for(int j=t;j>=k*w;--j){
					dp[j]=max(dp[j],dp[j-k*w]+k*c);
				}
				p-=k;
				k<<=1;
			}
			if(p>0){
				for(int j=t;j>=p*w;--j){
					dp[j]=max(dp[j],dp[j-p*w]+p*c);
				}
			}
		}
	}
	cout<<dp[t];
	return 0;
}