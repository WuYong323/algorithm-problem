#include<bits/stdc++.h>
#define N 105
#define inf -1e9
using namespace std;

int f,v;
int a[N][N];
int dp[N][N];
int pre[N][N];


int main()
{
	cin>>f>>v;
	for(int i=1;i<=f;++i){
		for(int j=1;j<=v;++j){
			cin>>a[i][j];
			pre[i][j]=-1;
			dp[i][j]=inf;
		}
	}
	for(int i=1;i<=v;++i){
		dp[1][i]=a[1][i];
	}
	for(int i=2;i<=f;++i){
		for(int j=i;j<=v;++j){
			int index=-1;
			int val=inf;
			for(int k=i-1;k<j;++k){
				if(dp[i-1][k]>val){
					val=dp[i-1][k];
					index=k;
				}
			}
			if(val>inf){
				dp[i][j]=val+a[i][j];
				pre[i][j]=index;
			}
		}
	}
	int bj=-1;
	int ans=inf;
	for(int i=f;i<=v;++i){
		if(dp[f][i]>ans){
			ans=dp[f][i];
			bj=i;
		}
	}
	vector<int> line(f+1);
	cout<<ans<<endl;
	for(int i=f;i>=1;--i){
		line[i]=bj;
		if(i>1){
			bj=pre[i][bj];
		}
	}
	for(int i=1;i<=f;++i){
		cout<<line[i]<<" ";
	}
	return 0;
}