#include<bits/stdc++.h>
using namespace std;

int dp[2510];

int main()
{
	int s[5];
	int sum=0;
	int time=0;
	int work[21];
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for (int i=1;i<=4;i++) {
		sum=0;
		for (int j=1;j<=s[i];j++){
			cin>>work[j];
			sum+=work[j];
		}
		for(int j=1;j<=s[i];j++){
			for(int k=sum/2;k>=work[j];k--){
				dp[k]=max(dp[k],dp[k-work[j]]+work[j]);
			}
		}
		time+=sum-dp[sum/2];
		for(int j=1;j<=sum/2;j++){
			dp[j]=0;
		}
	}
	cout<<time;
	return 0;
}