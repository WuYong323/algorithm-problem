#include<bits/stdc++.h>
#define N 10005
using namespace std;

int f[N][31];
int n,m;

int main()
{
	for(int i=1;i<=n;++i){
		cin>>f[i][0];
	}
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	int l,r;
	for(int i=1;i<=m;++i){
		cin>>l>>r;
		int k=log2(r-l+1);
		cout<<max(f[l][k],f[r-(1<<k)+1][k]);
	}
	return 0;
}