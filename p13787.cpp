#include<bits/stdc++.h>
#define ll long long
using namespace std;

int lst[5005][5005];
int a[5005][5005];
ll ans;

int main()
{
	int n,m;
	cin>>n>>m;
	int x1,y1,x2,y2;
	for(int i=1;i<=m;++i){
		cin>>x1>>y1>>x2>>y2;
		lst[x1][y1]+=1;
		lst[x1][y2+1]-=1;
		lst[x2+1][y1]-=1;
		lst[x2+1][y2+1]+=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=lst[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ans+=(i+j)^a[i][j];
		}
	}
	cout<<ans;
	return 0;
}