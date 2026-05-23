#include<bits/stdc++.h>
using namespace std;

int lst[2010][2010];
long long ans[2010][2010];

int main()
{
	int t,k;
	cin>>t>>k;
	lst[1][1]=lst[1][0]=lst[0][0]=1;
	for(int i=2;i<=2000;++i){
		lst[i][0]=1;
		for(int j=1;j<=i;++j){
			lst[i][j]=(lst[i-1][j-1]%k+lst[i-1][j]%k)%k;
			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
			if(lst[i][j]==0) ans[i][j]++;
		}
		ans[i][i+1]=ans[i][i];
	}
	int n,m;
	while(t--){
		cin>>n>>m;
		if(m>n) cout<<ans[n][n]<<endl;
		else cout<<ans[n][m]<<endl;
	}
	return 0;
}